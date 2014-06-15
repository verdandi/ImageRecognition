#include "ImageRecognitionService.h"

#include "Image.h"

namespace ImageRecognition {

Image::Image(const std::string& pathToImage)
	: pathToImage_(pathToImage),
	pathToImageDescription_(""),
	fileName_("")
{
	if (!Private::IsPathFileExist(pathToImage_)) {
		throw Error("File does not exist");
	}// end of if 

	Private::CreatePathToXML(pathToImage_, pathToImageDescription_);
	Private::GetFileNameFromPath(pathToImage_, fileName_);
}//end of Image::Image() 

Image::Image(const std::string& pathToImage,
			const std::string& pathToImageDescription)
	: pathToImage_(pathToImage),
	pathToImageDescription_(pathToImageDescription),
	fileName_("")
{
	if (!Private::IsPathFileExist(pathToImage_)) {
		throw Error("File does not exist");
	}// end of if 

	Private::GetFileNameFromPath(pathToImage_, fileName_);
}//end of Image::Image()

void Image::CreateDescription() {
#ifdef __IMAGE_RECOGNITION_DEBUG__
#define D_CreateDescription_ 1
	std::ofstream out("log.txt");
#else
#define D_CreateDescription_ 0
#endif

	try{
		cv::Mat img = cv::imread(pathToImage_);
		cv::resize(img, img, cv::Size(32,32));
		cv::HOGDescriptor descriptor(cv::Size(WIDHT_OF_IMAGE, HEIGHT_OF_IMAGE),
									cv::Size(WIDHT_OF_BIN, HEIGHT_OF_BIN),
									cv::Size(8,8), cv::Size(4,4), 9, 0, -1, 0, 0.2, 0, 64);

		std::vector<float> description;
		descriptor.compute(img, description);

		if (D_CreateDescription_) {
			PRINTSEQ(description, description.size(), out)
		}/* end of if */

		cv::FileStorage fs(pathToImageDescription_, cv::FileStorage::WRITE);
		fs << fileName_ << cv::Mat(1, description.size(), CV_32FC1, description.data());
	}
	catch(const cv::Exception& e){
		std::string error(e.what());
		throw Error(error);
	}
}//end of void Image::CreateDescription()

void Image::GetDescription(cv::Mat& description) const{
	if (!Private::IsPathFileExist(pathToImageDescription_)) {
		throw Error("Description for image " + pathToImage_ + "not created");
	}/* end of if */

	cv::FileStorage fs(pathToImageDescription_, cv::FileStorage::READ);
	fs["testImage2"] >> description;
}//end of cv::Mat& Image::GetDescription()

bool Image::IsDescriptionCreated() const noexcept {
	return Private::IsPathFileExist(pathToImageDescription_);
}//end of bool Image::IsDescriptionCreated()

} /* ImageRecognition */ 

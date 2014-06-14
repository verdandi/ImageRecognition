#include "ImageRecognitionService.h"

#include "Image.h"

#include <iostream>

namespace ImageRecognition {

Image::Image(const std::string& pathToImage)
	: pathToImage_(pathToImage),
	pathToImageDescription_("")
{}//end of Image::Image() 

Image::Image(const std::string& pathToImage,
			const std::string& pathToImageDescription)
	: pathToImage_(pathToImage),
	pathToImageDescription_(pathToImageDescription)
{}//end of Image::Image()

void Image::CreateDescription() {
#ifdef __IMAGE_RECOGNITION_DEBUG__
#define D_CreateDescription_ 1
	std::ofstream out("log.txt");
#else
#define D_CreateDescription_ 0
#endif

	//если путь к месту хранения описания не задан, то создадим описание рядом с картинкой
	if (pathToImageDescription_ == "") {
		Private::CreatePathToXML(pathToImage_, pathToImageDescription_);
	}/* end of if */

	std::string fileName;
	Private::GetFileNameFromPath(pathToImage_, fileName);

	if (D_CreateDescription_) {
		PRINTVAL(pathToImage_, out);
		PRINTVAL(pathToImageDescription_, out);
		PRINTVAL(fileName, out);
	}/* end of if */

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
		fs << fileName << cv::Mat(1, description.size(), CV_32FC1, description.data());
	}
	catch(const cv::Exception& e){
		std::string error(e.what());
		throw Error(error);
	}
}//end of void Image::CreateDescription()

} /* ImageRecognition */ 

#include "Defines.h"

#include "Image.h"
#include "ImageStorage.h"
#include "ImageRecognitionService.h"

#include "windows.h"

namespace ImageRecognition {

const char Storage::TRAIN_SAMPLE_NAME[] = "TrainSample";
const char Storage::TRAIN_SAMPLE_DESCRIPTION[] = "TrainSampleDescription";

Storage::Storage(const std::string& pathToStorage): pathToStorage_(pathToStorage), pathToTrainSample_("") {
#ifdef __IMAGE_RECOGNITION_DEBUG__
#define D_Storage_ 1
	std::ofstream out("logStorage.txt");
#else
#define D_Storage_ 0
#endif

	if (pathToStorage_[pathToStorage_.size()-1] != '/') {
		pathToStorage_ += SEPARATOR;
	}/* end of if */

	pathToTrainSample_ = pathToStorage_ + TRAIN_SAMPLE_NAME;
	pathToTrainSampleDescription_ = pathToStorage_ + TRAIN_SAMPLE_DESCRIPTION + SEPARATOR;

	if (D_Storage_) {
		PRINTVAL(pathToStorage_, out)
		PRINTVAL(pathToTrainSample_, out)
	}/* end of if */

	if (!Private::IsPathFileExist(pathToTrainSample_)) {
		throw Error("Dirctory " + pathToStorage_ + " not exist or not valid");
	}/* end of if */

	pathToTrainSample_ += SEPARATOR;

}//end of Storage::Storage()

void Storage::Create() {
	if(!::CreateDirectoryA(pathToTrainSampleDescription_.c_str(), NULL)){
		throw Error("Could not create folder " + pathToTrainSampleDescription_ + " , check user rights");
	}//end of if

	std::vector<std::string> directoryList;
	Private::GetSubDirectoryList(pathToTrainSample_, directoryList);
	for (size_t i = 0; i < directoryList.size(); ++i) {
		std::string pathToCurrentClassDescription = pathToTrainSampleDescription_ + directoryList[i] + SEPARATOR;
		if (!::CreateDirectoryA(pathToCurrentClassDescription.c_str(), NULL)){
			throw Error("Could not create folder " + pathToCurrentClassDescription + " , check user rights");
		}

		std::vector<std::string> imageList;
		std::string pathToCurrentClass = pathToTrainSample_ + directoryList[i] + SEPARATOR;
		Private::GetFileList(pathToCurrentClass, imageList);
		for (size_t i = 0; i < imageList.size(); ++i) {
			std::string pathToCurrentImage = pathToCurrentClass + SEPARATOR + imageList[i];
			std::string imageName;
			Private::GetFileNameFromPath(pathToCurrentImage, imageName);
			std::string pathToCurrentImageDescription = pathToCurrentClassDescription + imageName + ".xml";
			Image m(pathToCurrentImage, pathToCurrentImageDescription);
			m.CreateDescription();
		}//end of for
	}//end of for

}//end of void ImageStorage::Create()

} /* ImageRecognition */ 

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

	pathToTrainSample_ = pathToStorage_ + TRAIN_SAMPLE_NAME + SEPARATOR;
	pathToTrainSampleDescription_ = pathToStorage_ + TRAIN_SAMPLE_DESCRIPTION + SEPARATOR;

	if (D_Storage_) {
		PRINTVAL(pathToStorage_, out)
		PRINTVAL(pathToTrainSample_, out)
	}/* end of if */

	if (!Private::IsPathFileExist(pathToTrainSample_)) {
		throw Error("Dirctory " + pathToStorage_ + " not exist or not valid");
	}/* end of if */

	std::vector<std::string> subDirectoryList;
	Private::GetSubDirectoryList(pathToTrainSample_, subDirectoryList);

	for (size_t i = 0; i < subDirectoryList.size(); ++i) {
		char dig = '0'+(i+1);
		if (subDirectoryList[i][0] != dig) {
			throw Error("Directory " + pathToTrainSample_ + "has bad structure");
		}/* end of if */
	}//end of for
}//end of Storage::Storage()

void Storage::Create() {
	//проверяем не было ли хранилище создано ранее
	if (Private::IsPathFileExist(pathToTrainSampleDescription_)) {
		throw Error("Storage was created. If you want to create new storage, first remove old");
	}/* end of if */

	//создвем хранилище
	if(!::CreateDirectoryA(pathToTrainSampleDescription_.c_str(), NULL)){
		throw Error("Could not create folder " + pathToTrainSampleDescription_ + " , check user rights");
	}//end of if

	//получаем список поддиректорий каталога <pathToTrainSample_>
	//и создаем аналогичную структуру в каталоге <pathToTrainSampleDescription_>
	std::vector<std::string> directoryList;
	Private::GetSubDirectoryList(pathToTrainSample_, directoryList);
	for (size_t i = 0; i < directoryList.size(); ++i) {
		std::string pathToCurrentClassDescription = pathToTrainSampleDescription_ + directoryList[i] + SEPARATOR;
		if (!::CreateDirectoryA(pathToCurrentClassDescription.c_str(), NULL)){
			throw Error("Could not create folder " + pathToCurrentClassDescription + " , check user rights");
		}

		//создаем описание для каждой картинки в каждом подкаталоге каталога <pathToTrainSample_>
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

void Storage::Remove() {
	std::vector<std::string> subDirectoryList;
	Private::GetSubDirectoryList(pathToTrainSampleDescription_, subDirectoryList);
	for (size_t i = 0; i < subDirectoryList.size(); ++i) {
		std::string curDir = pathToTrainSampleDescription_ + subDirectoryList[i] + SEPARATOR;
		std::vector<std::string> fileList;
		Private::GetFileList(curDir, fileList);
		for (size_t i = 0; i < fileList.size(); ++i) {
			std::string pathToFile = curDir + fileList[i];
			::DeleteFileA(pathToFile.c_str());
		}//end of for

		::RemoveDirectoryA(curDir.c_str());
	}//end of for

	::RemoveDirectoryA(pathToTrainSampleDescription_.c_str());
}//end of void Storage::Remove()

} /* ImageRecognition */ 

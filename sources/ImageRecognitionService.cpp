#include "ImageRecognitionService.h"

#include "windows.h"
#include "shlwapi.h"

#include <cstring>

namespace ImageRecognition {

namespace Private {

void CreatePathToXML(const std::string& pathToImage, std::string& pathToXML) {
		std::string suffix = ".xml";
		size_t dotPos = pathToImage.find_last_of(".");
		pathToXML = std::string(pathToImage.begin(), pathToImage.begin() + dotPos) + suffix;
}//end of void CreatePathToXML()

void GetFileNameFromPath(const std::string& pathToFile, std::string& name) {
	int slashPos = pathToFile.find_last_of("/");
	int dotPos = pathToFile.find_last_of(".");
	name = std::string(pathToFile.begin() + slashPos+1, pathToFile.begin() + dotPos);
}//end of void GetFileNameFromPath()

bool IsPathFileExist(const std::string& pathToFile) {
	int ans = ::PathFileExistsA(pathToFile.c_str());
	if (ans == 1) {
		return true;
	}/* end of if */
	else if(ans == 0){
		return false;
	}//end of if

	return false;
}//end of bool IsFileExist()

void GetSubDirectoryList(const std::string& pathToDirectory, std::vector<std::string>& subDirectoryList) {
#ifdef __IMAGE_RECOGNITION_DEBUG__
#define D_GetSubDirectoryList_ 1
	std::ofstream out("logGetSubDirectoryList.txt");
#else
#define D_GetSubDirectoryList_ 0
#endif

	//создаем шаблон для поиска
	std::string findTemplate = pathToDirectory + "*.*";

	subDirectoryList.clear();

	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFileA(findTemplate.c_str(), &fd);
	
	do{
		if( (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) && std::strcmp(fd.cFileName, ".") !=0 && std::strcmp(fd.cFileName, "..") != 0 ) {
			subDirectoryList.push_back(fd.cFileName);
		}
	}while (::FindNextFile(hFind, &fd) );
	
	::FindClose(hFind);

	if (D_GetSubDirectoryList_) {
		PRINTSEQ(subDirectoryList, subDirectoryList.size(), out);
	}/* end of if */

}//end of void GetSubDirectoryList()

void GetFileList(const std::string& pathToDirectory, std::vector<std::string>& fileList) {
#ifdef __IMAGE_RECOGNITION_DEBUG__
#define D_GetFileList_ 1
	std::ofstream out("logGetFileList.txt");
#else
#define D_GetFileList_ 0
#endif
	//создаем шаблон для поиска
	std::string findTemplate = pathToDirectory + "*.*";

	fileList.clear();

	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFileA(findTemplate.c_str(), &fd);
	
	do{
		if( (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0 ) {
			fileList.push_back(fd.cFileName);
		}
	}while (::FindNextFile(hFind, &fd) );
	
	::FindClose(hFind);

	if (D_GetFileList_) {
		PRINTSEQ(fileList, fileList.size(), out);
	}/* end of if */

}//end of void GetFileList()

} /* Private */ 

} /* ImageRecognition */ 

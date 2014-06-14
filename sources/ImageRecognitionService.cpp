#include "ImageRecognitionService.h"

#include "windows.h"

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

bool IsFileExist(const std::string& pathToFile) {
	HANDLE h = ::CreateFileA(pathToFile.c_str(), GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	if (h == INVALID_HANDLE_VALUE) {
		return false;
	}/* end of if */

	::CloseHandle(h);
	return true;
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
	
	::CloseHandle(hFind);

	if (D_GetSubDirectoryList_) {
		PRINTSEQ(subDirectoryList, subDirectoryList.size(), out);
	}/* end of if */

}//end of void GetSubDirectoryList()

} /* Private */ 

} /* ImageRecognition */ 

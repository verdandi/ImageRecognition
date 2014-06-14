#include "ImageRecognitionService.h"

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

} /* Private */ 

} /* ImageRecognition */ 

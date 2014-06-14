#include "ImageRecognitionService.h"

namespace ImageRecognition {

namespace Private {

void CreatePathToXML(const std::string& pathToImage, std::string& pathToXML) {
		std::string suffix = ".xml";
		size_t dotPos = pathToImage.find_last_of(".");
		pathToXML = std::string(pathToImage.begin(), pathToImage.begin() + dotPos) + suffix;
}//end of void CreatePathToXML()

} /* Private */ 

} /* ImageRecognition */ 

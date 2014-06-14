#ifndef IMAGE_RECOGNITION_SERVICE_H_
#define IMAGE_RECOGNITION_SERVICE_H_

#include "Defines.h"

#include <string>

namespace ImageRecognition {

namespace Private {

/*
получить путь к XML-фуйлу по пути к картинке.
Функция заменяет расширение файла, путь к которому указана в строке <pathToImage>
на расширение .xml. Резульат записывается в строку pathToXML
*/
void CreatePathToXML(const std::string& pathToImage, std::string& pathToXML);

void GetFileNameFromPath(const std::string& pathToFile, std::string& name);

} /* Private */ 

} /* ImageRecognition */ 

#endif /* end of include guard: IMAGE_RECOGNITION_SERVICE_H_ */


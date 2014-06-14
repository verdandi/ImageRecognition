#ifndef IMAGE_RECOGNITION_SERVICE_H_
#define IMAGE_RECOGNITION_SERVICE_H_

#include "Defines.h"

#include <string>
#include <vector>

namespace ImageRecognition {

namespace Private {

/*
получить путь к XML-фуйлу по пути к картинке.
Функция заменяет расширение файла, путь к которому указана в строке <pathToImage>
на расширение .xml. Резульат записывается в строку pathToXML
*/
void CreatePathToXML(const std::string& pathToImage, std::string& pathToXML);

/*
получить им файла из пуит к нему.
Функция копирует имя файла из <pathToFile> в <name>
*/
void GetFileNameFromPath(const std::string& pathToFile, std::string& name);

/*
Проверить существует ли файл по пути <pathToFile>
*/
bool IsFileExist(const std::string& pathToFile);

void GetSubDirectoryList(const std::string& pathToDirectory, std::vector<std::string>& subDirectoryList);

} /* Private */ 

} /* ImageRecognition */ 

#endif /* end of include guard: IMAGE_RECOGNITION_SERVICE_H_ */


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
bool IsPathFileExist(const std::string& pathToFile);

/*
Получить список поддиректорий в директории <pathToDirectory>
(можно получить список ТОЛЬКО поддиректорий. Если в папке встречаются
файлы - они игнорируются)
Принимаемые параметры:
- pathToDirectory - путь к директории, список поддиректориий хочется получить
(должен заканчиваться слешом ('/'))
- subDirectoryList - сюда список поддиректорий будет сохранен
*/
void GetSubDirectoryList(const std::string& pathToDirectory, std::vector<std::string>& subDirectoryList);

/*
Получить список файлов в директории <pathToDirectory> (можно 
получить список ТОЛЬКО файлов. Если в папке встречаются директории, то они игнорируются)
Принимаемые параметры:
- pathToDirectory - путь к директории, список файлов в которой хочется получить 
(должен оканчиваться слешом ('/'))
- fileList - сюда список файлов будет сохранен
*/
void GetFileList(const std::string& pathToDirectory, std::vector<std::string>& fileList);

} /* Private */ 

} /* ImageRecognition */ 

#endif /* end of include guard: IMAGE_RECOGNITION_SERVICE_H_ */


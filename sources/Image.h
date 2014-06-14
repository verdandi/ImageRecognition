#ifndef IMAGE_H_
#define IMAGE_H_

#include "Defines.h"
#include "ImageRecognitionError.h"

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"

namespace ImageRecognition {

class Image {
/*
класс для работы с изображениями
*/
public:
	/*
	Конструктор.
	Принимаемые параметры:
	- pathToImage - путь к изображению.
	Примечание! Имя файла в задаваемых путях должно быть длинее 1 символа
	и не должно содержать только цифры
	*/
	explicit Image (const std::string& pathToImage);

	/*
	Конструктор.
	Принимаемые параметры:
	- pathToImage - путь к изображению.
	- pathToImageDescription - путь к описанию изображения
	Примечание! Имя файла в задаваемых путях должно быть длинее 1 символа
	и не должно содержать только цифры
	*/
	Image (const std::string& pathToImage, const std::string& pathToImageDescription);

	~Image() {}

	/*
	создать .xml-файл описания параметров картинки.
	В случае если путь к описанию задан, оно создается по этому пути.
	В случае если путь к описанию НЕ задан - оно создается рядом с картинкой.
	Функция может генерировать исключения вида ImageRecognition::Error
	*/
	void CreateDescription();

	/*
	Выдать описание изображения
	Принимаемые параметры:
	description - переменная, в которую считывается описание изображения
	В случае если описание не создано, генерирует исключение типа Error
	*/
	void GetDescription(cv::Mat& description) const;

	/*
	Проверить создано ли описание
	*/
	bool IsDescriptionCreated() const noexcept;

private:
	static const int HEIGHT_OF_IMAGE = 32;
	static const int WIDHT_OF_IMAGE = 32;
	static const int HEIGHT_OF_BIN = 8;
	static const int WIDHT_OF_BIN = 8;

	std::string pathToImage_;
	std::string pathToImageDescription_;
	std::string fileName_;
};//end of declaration class Image

} /* ImageRecognition */ 

#endif /* end of include guard: IMAGE_H_ */

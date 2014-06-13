#ifndef IMAGE_H_
#define IMAGE_H_

#include <string>

#include "opencv/cv.h"

namespace ImageRecognition {

class Image {
/*
класс для работы с изображениями
*/
public:
	Image (const std::wstring& pathToImage);
	Image (const std::wstring& pathToImage, const std::wstring& pathToImageDescription);
	~Image() {}

	void CreateDescription();
	GetDescription(cv::Mat& description);
	bool IsDescriptionCreated();

private:
	std::wstring pathToImage_;
	std::wstring pathToImageDescription_;
};//end of declaration class Image

} /* ImageRecognition */ 

#endif /* end of include guard: IMAGE_H_ */


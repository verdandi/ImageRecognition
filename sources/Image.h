#ifndef IMAGE_H_
#define IMAGE_H_

#include "Defines.h"
#include "ImageRecognitionError.h"

#include <string>

//#include "opencv/cv.hpp"
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
	Image (const std::string& pathToImage);
	Image (const std::string& pathToImage, const std::string& pathToImageDescription);
	~Image() {}

	void CreateDescription();
	//GetDescription(cv::Mat& description);
	bool IsDescriptionCreated();

private:
	static const int HEIGHT_OF_IMAGE = 32;
	static const int WIDHT_OF_IMAGE = 32;
	static const int HEIGHT_OF_BIN = 8;
	static const int WIDHT_OF_BIN = 8;

	std::string pathToImage_;
	std::string pathToImageDescription_;


};//end of declaration class Image

} /* ImageRecognition */ 

#endif /* end of include guard: IMAGE_H_ */


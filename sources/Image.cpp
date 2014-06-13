#include "Image.h"

namespace ImageRecognition {

Image::Image(const std::wstring& pathToImage)
	: pathToImage_(pathToImage),
	pathToImageDescription_(L"")
{}//end of Image::Image() 

Image::Image(const std::wstring& pathToImage,
			const std::wstring& pathToImageDescription)
	: pathToImage_(pathToImage),
	pathToImageDescription_(pathToImageDescription)
{}//end of Image::Image()

} /* ImageRecognition */ 

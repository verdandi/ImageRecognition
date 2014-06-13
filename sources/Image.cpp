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

void Image::CreateDescription() {
	//если путь к месту хранения описания не задан, то создадим описание рядом с картинкой
	if (pathToImageDescription_ == L"") {
		std::wstring suffix = L".xml";
		size_t dotPos = pathToImage_.find_last_of(L".");
		pathToImageDescription_ = std::wstring(pathToImage_.begin(), pathToImage_.begin() + dotPos) + suffix;
	}/* end of if */
}//end of void Image::CreateDescription()

} /* ImageRecognition */ 

#include "ImageRecognitionError.h"

namespace ImageRecognition {

const std::string& Error::What() const noexcept{
	return errorMessage_;
}//end of const std::wstring& Error::What()


} /* ImageRecognition */ 

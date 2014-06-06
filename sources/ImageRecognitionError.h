#include <string>
#include <exception>

namespace ImageRecognition {

class Error{
/*
Exception class for library 'ImageRecognition'
*/
public:
	Error (const std::wstring& errorMessage): errorMessage_(errorMessage) {}
	~Error () noexcept {}

	const std::wstring& What() const noexcept;

private:
	std::wstring errorMessage_;

	Error(const Error&);
	Error& operator=(const Error&);
};//end of declaration class ImageRecognitionError

} /* ImageRecognition */ 

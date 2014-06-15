#ifndef IMAGE_RECOGNITION_ERROR_H_
#define IMAGE_RECOGNITION_ERROR_H_

#include <string>
#include <exception>

namespace ImageRecognition {

class Error{
/*
Exception class for library 'ImageRecognition'
*/
public:
	Error (const std::string& errorMessage): errorMessage_(errorMessage) {}
	~Error () noexcept {}

	const std::string& What() const noexcept;

private:
	std::string errorMessage_;

	//Error(const Error&);
	//Error& operator=(const Error&);
};//end of declaration class ImageRecognitionError

} /* ImageRecognition */ 

#endif /* end of include guard: IMAGE_RECOGNITION_ERROR_H_ */

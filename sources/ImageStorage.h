#ifndef IMAGE_STORAGE_H_
#define IMAGE_STORAGE_H_

#include "Defines.h"
#include "ImageRecognitionError.h"

#include <string>

namespace ImageRecognition {

class Storage {
/*
Класс, моделирующий хранилище изображений
*/
public:
	explicit Storage (const std::string& pathToStorage);
	void Create();
	~Storage (){}

private:
	static const char TRAIN_SAMPLE_NAME[];
	static const char TRAIN_SAMPLE_DESCRIPTION[];
	static const char SEPARATOR = '/';

	std::string pathToStorage_;
	std::string pathToTrainSample_;
	std::string pathToTrainSampleDescription_;

};//end of declaration class Storage

} /* ImageRecognition */ 

#endif /* end of include guard: IMAGE_STORAGE_H_ */


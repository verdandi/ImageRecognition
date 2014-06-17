#ifndef IMAGE_STORAGE_H_
#define IMAGE_STORAGE_H_

#include "Defines.h"
#include "ImageRecognitionError.h"
#include "Image.h"

#include <string>

namespace ImageRecognition {

class Storage {
/*
Класс, моделирующий хранилище изображений
*/
public:
	/*
	Конструктор класса.
	Принимает параметр pathToStorage - путь к хранилищу.
	Для того чтобы каталог, путь к которому передается в переменной
	<pathToStorage> мог выступать в качестве хранилища, он должен содержать
	опучающую выборку. Причем обучающая выборка должна содержаться строго в каталоге с именем
	<pathToStorage>/TrainSample, кторый должен иметь подкаталоги с именами "1", "2" и тд
	по количеству классов в обучающей выборке. При несоблюдении данных условий каталог, путь
	к которому передается в конструктор, признается невалидным и генерируется исключение с
	соответствующим сообщением.
	*/
	explicit Storage (const std::string& pathToStorage);

	//~Storage (){}

	/*
	Создать хранилище.
	Создает рядом с каталогом <pathToStorage>/TrainSample каталог
	<pathToStorage>/TrainSampleDescription со структурой подкаталогов, повторяющей
	структурку подкаталогов в каталоге <pathToStorage>/TrainSample. Однако, в каждом
	подкаталоге хранятся уже не изображения, а .xml-файлы с описанием соответствующий картинки.
	Например, пусть каталог <pathToStorage>/TrainSample содержит подкаталоги
	<pathToStorage>/TrainSample/1 и <pathToStorage>/TrainSample/2, и пусть в каталоге "1"
	есть изобрежние s1.jpg, а в каталоге "2" - изображение s2.jpg. Тогда данная функция 
	создаст каталог <pathToStorage>/TrainSampleDescription с подкаталогами "1" и "2", в каждом
	из которых будут созданы файлы s1.xml и s2.xml  соответственно.
	Если хранилище уже было создано ранее, вызывается исключение типа Error
	*/
	void Create();

	/*
	удалить ранее созданное хранилище
	*/
	void Remove();

	/*
	проверить создано ли хранилище
	Возвращаемое значение:
	true - если создано.
	*/
	bool WasCreated() const;

	void GetImages(const std::vector<int>& classNumbers, std::vector<Image>& imageList) const;
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


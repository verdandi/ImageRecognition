#include "TestFramework.h"

#include "../sources/ImageStorage.h"

#include "../sources/ImageRecognitionService.h"

#include "windows.h"

namespace ImageRecognition {

class StorageTest: public ::testing::Test {
public:
	std::string pathToStorage1_;

	virtual void SetUp(){
		pathToStorage1_ = "../tests_service/ts1";
	}

	virtual void TearDown() {}

};//end of declaration class ImageStorageTest: public ::testing::Test

TEST_F(StorageTest, Construction){
	EXPECT_NO_THROW(Storage("../tests_service/ts1"));

	EXPECT_THROW(Storage("../tests_service"), Error);

	EXPECT_THROW(Storage("../tests_service/ts4"), Error);
}

TEST_F(StorageTest, CreateRemove){
	Storage s(pathToStorage1_);
	s.Create();

	EXPECT_TRUE(Private::IsPathFileExist("../tests_service/ts1/TrainSampleDescription"));
	EXPECT_TRUE(Private::IsPathFileExist("../tests_service/ts1/TrainSampleDescription/1"));
	EXPECT_TRUE(Private::IsPathFileExist("../tests_service/ts1/TrainSampleDescription/2"));
	EXPECT_TRUE(Private::IsPathFileExist("../tests_service/ts1/TrainSampleDescription/3"));
	EXPECT_TRUE(Private::IsPathFileExist("../tests_service/ts1/TrainSampleDescription/1/s1.xml"));
	EXPECT_TRUE(Private::IsPathFileExist("../tests_service/ts1/TrainSampleDescription/1/s2.xml"));
	EXPECT_TRUE(Private::IsPathFileExist("../tests_service/ts1/TrainSampleDescription/2/s3.xml"));
	EXPECT_TRUE(Private::IsPathFileExist("../tests_service/ts1/TrainSampleDescription/2/s4.xml"));
	EXPECT_TRUE(Private::IsPathFileExist("../tests_service/ts1/TrainSampleDescription/2/s5.xml"));
	EXPECT_TRUE(Private::IsPathFileExist("../tests_service/ts1/TrainSampleDescription/3/s6.xml"));

	s.Remove();

	EXPECT_FALSE(Private::IsPathFileExist("../tests_service/ts1/TrainSampleDescription"));
}

TEST_F(StorageTest, StorageWasCreated){
	Storage s("../tests_service/ts3");
	EXPECT_THROW(s.Create(), Error);
}

TEST_F(StorageTest, WasStorageCreated){
	Storage s("../tests_service/ts3");
	
	EXPECT_TRUE(s.WasCreated());
}

TEST_F(StorageTest, GetImages){
	Storage s("../tests_service/ts3");
	std::vector<int> classNumbers;
	classNumbers.push_back(2);
	std::vector<Image> images;

	s.GetImages(classNumbers, images);
	EXPECT_TRUE(images.size() == 3);

	classNumbers.clear();
	classNumbers.push_back(1);
	classNumbers.push_back(3);

	s.GetImages(classNumbers, images);
	EXPECT_TRUE(images.size() == 3);
}

} /* ImageRecognition */ 

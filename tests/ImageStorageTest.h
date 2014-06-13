#include "TestFramework.h"

#include "ImageStorage.h"

namespace ImageRecognition {

class StorageTest: public ::testing::Test {
public:
	std::wstring pathToStorage_;

	virtual void SetUp(){
	}

	virtual void TearDown() {}

};//end of declaration class ImageStorageTest: public ::testing::Test

TEST_F(StorageTest, CreateTest){
	EXPECT_TRUE(1 == 1);
}

} /* ImageRecognition */ 

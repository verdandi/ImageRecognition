#include "TestFramework.h"

#include "../sources/ImageRecognitionService.h"

namespace ImageRecognition {

namespace Private {

class ImageRecognitionServiceTest: public ::testing::Test {
public:
	std::string pathToImage_;
	std::string pathToXML_;
	std::string name_;

	virtual void SetUp() {
		pathToImage_ = "../tests_service/testImage1.jpg";
		pathToXML_ = "../tests_service/testImage1.xml";
		name_ = "testImage1";
	}

	virtual void TearDown() {}

};//end of declaration class ImageRecognitionServiceTest: public ::testing::Test

TEST_F(ImageRecognitionServiceTest, CreatePathToXML){
	std::string test;
	CreatePathToXML(pathToImage_, test);
	EXPECT_TRUE(test == pathToXML_);
}

TEST_F(ImageRecognitionServiceTest, GetFileNameFromPath){
#ifdef __IMAGE_RECOGNITION_DEBUG__
#define D_GetFileFromPath_ 1
#else
#define D_GetFileFromPath_ 0
#endif

	std::string test;
	GetFileNameFromPath(pathToImage_, test);

	if (D_GetFileFromPath_) {
		PRINTVAL(test)
	}/* end of if */

	EXPECT_TRUE(test == name_);
}

} /* Private */ 

} /* ImageRecognition */ 

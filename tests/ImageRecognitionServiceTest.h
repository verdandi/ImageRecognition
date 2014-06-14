#include "TestFramework.h"

#include "../sources/ImageRecognitionService.h"

namespace ImageRecognition {

namespace Private {

class ImageRecognitionServiceTest: public ::testing::Test {
public:
	std::string pathToImage_;
	std::string pathToXML_;

	virtual void SetUp() {
		pathToImage_ = "../tests_service/testImage1.jpg";
		pathToXML_ = "../tests_service/testImage1.xml";
	}

	virtual void TearDown() {}

};//end of declaration class ImageRecognitionServiceTest: public ::testing::Test

TEST_F(ImageRecognitionServiceTest, CreatePathToXML){
	std::string test;
	CreatePathToXML(pathToImage_, test);
	EXPECT_TRUE(test == pathToXML_);
}

} /* Private */ 

} /* ImageRecognition */ 

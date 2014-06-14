#include "TestFramework.h"

#include "../sources/ImageRecognitionService.h"

namespace ImageRecognition {

namespace Private {

class ImageRecognitionServiceTest: public ::testing::Test {
public:
	std::string pathToImage_;
	std::string pathToXML_;
	std::string name_;
	std::string notValidPath_;
	std::string pathToDirectory_;

	virtual void SetUp() {
		pathToImage_ = "../tests_service/testImage1.jpg";
		notValidPath_ = "../tests_service/testImage3.jpg";
		pathToXML_ = "../tests_service/testImage1.xml";
		name_ = "testImage1";
		pathToDirectory_ = "../tests_service/ts1/TrainSample/";
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
	std::ofstream out("log.txt");
#else
#define D_GetFileFromPath_ 0
#endif

	std::string test;
	GetFileNameFromPath(pathToImage_, test);

	if (D_GetFileFromPath_) {
		PRINTVAL(test, out)
	}/* end of if */

	EXPECT_TRUE(test == name_);
}

TEST_F(ImageRecognitionServiceTest, IsFileExist){
	bool ans = IsFileExist(pathToImage_);
	EXPECT_TRUE(ans == true);

	ans = IsFileExist(notValidPath_);
	EXPECT_TRUE(ans == false);
}

TEST_F(ImageRecognitionServiceTest, GetSubDirectoryList){
	std::vector<std::string> expected;
	expected.push_back("1");
	expected.push_back("2");
	expected.push_back("3");

	std::vector<std::string> fact;
	GetSubDirectoryList(pathToDirectory_, fact);

	EXPECT_TRUE(expected.size() == fact.size());

	if (expected.size() == fact.size()) {
		for (size_t i = 0; i < fact.size(); ++i) {
			EXPECT_TRUE(expected[i] == fact[i]);
		}//end of for
	}/* end of if */
}

} /* Private */ 

} /* ImageRecognition */ 

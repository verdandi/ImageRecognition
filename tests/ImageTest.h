#include "TestFramework.h"

#include "../sources/Image.h"

#include "windows.h"

namespace ImageRecognition {

class ImageTest: public ::testing::Test {
public:
	std::string pathToTestImage1_;
	std::string pathToTestImage1Description_;
	std::string pathToTestImage2_;
	std::string pathToTestImage2Description_;
	std::string pathToTestImage3_;
	std::string pathToTestImage3Description_;

	virtual void SetUp(){
		pathToTestImage1_ = "../tests_service/testImage1.jpg";
		pathToTestImage1Description_ = "../tests_service/testImage1.xml";
		pathToTestImage2_ = "../tests_service/ts2/TrainSample/1/s1.jpg";
		pathToTestImage2Description_ = "../tests_service/ts2/TrainSampleDescription/1/s1.xml";
		pathToTestImage3_ = "../tests_service/ts2/TrainSample/1/s3.jpg";
		pathToTestImage3Description_ = "../tests_service/ts2/TrainSampleDescription/1/s3.xml";
	}

	virtual void TearDown(){}
};//end of declaration class ImageTest


TEST_F(ImageTest, CreateDescription){
	Image m1(pathToTestImage1_);
	HANDLE h = ::CreateFileA(pathToTestImage1Description_.c_str(), GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	EXPECT_TRUE(h == INVALID_HANDLE_VALUE);
	m1.CreateDescription();
	h = ::CreateFileA(pathToTestImage1Description_.c_str(), GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	EXPECT_TRUE(h != INVALID_HANDLE_VALUE);

	::CloseHandle(h);
	::DeleteFileA(pathToTestImage1Description_.c_str());

	Image m2(pathToTestImage2_, pathToTestImage2Description_);

	h = ::CreateFileA(pathToTestImage2Description_.c_str(), GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	EXPECT_TRUE(h == INVALID_HANDLE_VALUE);

	m2.CreateDescription();
	h = ::CreateFileA(pathToTestImage2Description_.c_str(), GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	EXPECT_TRUE(h != INVALID_HANDLE_VALUE);

	::CloseHandle(h);
	::DeleteFileA(pathToTestImage2Description_.c_str());

	Image m3(pathToTestImage3_, pathToTestImage3Description_);
	EXPECT_THROW(m3.CreateDescription(), Error);
}

} /* ImageRecognition */ 

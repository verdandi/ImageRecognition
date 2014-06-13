#include "TestFramework.h"

#include "../sources/Image.h"

#include "windows.h"

namespace ImageRecognition {

class ImageTest: public ::testing::Test {
public:
	std::wstring pathToTestImage1_;
	std::wstring pathToTestImage1Description_;
	std::wstring pathToTestImage2_;
	std::wstring pathToTestImage2Description_;

	virtual void SetUp(){
		pathToTestImage1_ = L"../tests_service/testImage1.jpg";
		pathToTestImage1Description_ = L"../tests_service/testImage1.xml";
		pathToTestImage2_ = L"../tests_service/ts2/TrainSample/1/1.jpg";
		pathToTestImage2Description_ = L"../tests_service/ts2/TrainSampleDescription/1/1.xml";
	}

	virtual void TearDown(){}
};//end of declaration class ImageTest

TEST_F(ImageTest, CreateDescription){
	Image m(pathToTestImage1_);
	HANDLE h = ::CreateFileW(pathToTestImage1Description_.c_str(), GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	EXPECT_TRUE(h == INVALID_HANDLE_VALUE);
	m.CreateDescription();
	h = ::CreateFileW(pathToTestImage1Description_.c_str(), GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	EXPECT_TRUE(h != INVALID_HANDLE_VALUE);

	::CloseHandle(h);
	::DeleteFileW(pathToTestImage1Description_.c_str());

	Image m1(pathToTestImage2_, pathToTestImage2Description_);
	h = ::CreateFileW(pathToTestImage2Description_.c_str(), GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	EXPECT_TRUE(h == INVALID_HANDLE_VALUE);
	m1.CreateDescription();
	h = ::CreateFileW(pathToTestImage2Description_.c_str(), GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	EXPECT_TRUE(h != INVALID_HANDLE_VALUE);
	::CloseHandle(h);
}

} /* ImageRecognition */ 

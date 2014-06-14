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
	std::string pathToTestImage4_;
	std::string pathToTestImage4Description_;

	virtual void SetUp(){
		pathToTestImage1_ = "../tests_service/testImage1.jpg";
		pathToTestImage1Description_ = "../tests_service/testImage1.xml";
		pathToTestImage2_ = "../tests_service/ts2/TrainSample/1/s1.jpg";
		pathToTestImage2Description_ = "../tests_service/ts2/TrainSampleDescription/1/s1.xml";
		pathToTestImage3_ = "../tests_service/ts2/TrainSample/1/s3.jpg";
		pathToTestImage3Description_ = "../tests_service/ts2/TrainSampleDescription/1/s3.xml";
		pathToTestImage4_ = "../tests_service/testImage2.jpg";
		pathToTestImage4Description_ = "../tests_service/testImage2.xml";
	}

	virtual void TearDown(){}
};//end of declaration class ImageTest

TEST_F(ImageTest, Construction){
	EXPECT_NO_THROW(Image(pathToTestImage2_, pathToTestImage2Description_));

	EXPECT_THROW(Image(pathToTestImage3_, pathToTestImage3Description_), Error);
}

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
}

TEST_F(ImageTest, IsDescriptionCreated){
	Image m(pathToTestImage4_);
	EXPECT_TRUE(m.IsDescriptionCreated());
	Image m1(pathToTestImage1_);
	EXPECT_FALSE(m1.IsDescriptionCreated());
}

//TEST_F(ImageTest, GetDescription){
	//cv::Mat expected;
	//cv::Mat fact;
	//Image m(pathToTestImage4_);
	//cv::FileStorage fs(pathToTestImage4Description_, cv::FileStorage::READ);
	//fs["testImage2"] >> expected;
	//m.GetDescription(fact);
	//EXPECT_TRUE(expected.size == fact.size);
	//if (expected.size == fact.size){
		//cv::MatIterator_<float> eit = expected.begin<float>();
		//cv::MatIterator_<float> fit = fact.begin<float>();
		//for (; fit != fact.end<float>();) {
			//EXPECT_TRUE(*fit == *eit);
		//}//end of for
	//}
//}

} /* ImageRecognition */ 

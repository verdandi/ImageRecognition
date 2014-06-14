#ifndef DEFINES_H_
#define DEFINES_H_

#ifdef __IMAGE_RECOGNITION_DEBUG__
#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
#include <iterator>
#include <string>
#include <stack>
#include <cassert>
#endif

#ifdef __IMAGE_RECOGNITION_DEBUG__
#include <cstdio>
#include <cstdlib>
#include <ctime>
#endif

#ifdef __IMAGE_RECOGNITION_TEST__
#include "gtest/gtest_prod.h"
#endif

#ifdef __IMAGE_RECOGNITION_DEBUG__
#define TRACE(arg) {std::cout << #arg << std::endl; arg;}
#else
#define TRACE(arg) 
#endif

#ifdef __IMAGE_RECOGNITION_DEBUG__
#define PRINTSEQ(seq, size, out) {\
	out << "------------------------------\n"; \
	out << "file: " << __FILE__ << ", str. " << __LINE__ << ":" << #seq << ":" << "\n"; \
	for(size_t i = 0; i < (size); ++i){ \
		out << "el #" << i << ": " << seq[i] << "\n"; \
	} \
	out << "------------------------------\n"; \
}
#else
#define PRINTSEQ(seq, size, out)
#endif

#ifdef __IMAGE_RECOGNITION_DEBUG__
#define PRINTVAL(val, out) {out << "file: " << __FILE__ << ", str. " << __LINE__ << ": " << #val << " - " << val << "\n";}
#else
#define PRINTVAL(val, out)
#endif

//using std::cin;

//#ifdef __ALGORITHM_DEBUG__
////#define cin in
//#endif

#endif /* end of include guard: DEFINES_H_ */

#include "Test.h"
#include <iostream>

int Test::failedNum = 0;
int Test::totalNum = 0;

void Test::check(bool expr, const char *func, const char  *filename, size_t lineNum) {
	if (!expr) {
		std::cout << "Test failed: " << func << " in " << filename << ':' << lineNum << '\n';
		++failedNum;
	}
	++totalNum;
}

void Test::showFinalResult() {
	if (failedNum == 0) {
		std::cout << "All tests passed.\n";
	} else {
		std::cout << "Failed " << failedNum << " of " << totalNum << " tests.\n"; 
	}
}

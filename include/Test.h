#ifndef _TEST_H_
#define _TEST_H_ 

#include <stddef.h>

#define DO_CHECK(EXPR) check(EXPR, __FUNCTION__, __FILE__, __LINE__)

class Test {
protected:
	static int failedNum; 
	static int totalNum; 
public:
	static void check(bool expr, const char *func, const char  *filename, size_t lineNum); 
	static void showFinalResult();
	virtual void runAllTests() = 0;
};

#endif

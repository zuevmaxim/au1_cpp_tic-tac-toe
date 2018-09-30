#ifndef _BOARD_TEST_H_
#define _BOARD_TEST_H_ 

#include "Test.h"

class BoardTest: public Test {
public:
	void test_canMove1();
	void test_canMove2();
	void test_canMove3();
	
	void test_makeMove1();
	void test_makeMove2();
	void test_makeMove3();
	
	void test_isWin1();
	void test_isWin2();
	void test_isWin3();
	void test_isWin4();
	void test_isWin5();
	void test_isWin6();
	void test_isWin7();
	void test_isWin8();
	
	void test_getCage1();
	void test_getCage2();
	void test_getCage3();
	void test_getCage4();

	void runAllTests();
};

#endif

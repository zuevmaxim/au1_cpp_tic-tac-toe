#include "BoardTest.h"
#include "Board.h"

void BoardTest::test_canMove1() {
	Board board;
	board.makeMove(0, 0, X);
	DO_CHECK(board.canMove(0, 0, O) == 0);
}

void BoardTest::test_canMove2() {
	Board board;
	DO_CHECK(board.canMove(0, 0, O) == 1);
}

void BoardTest::test_canMove3() {
	Board board;
	DO_CHECK(board.canMove(-1, 0, O) == 0);
}
	
void BoardTest::test_makeMove1() {
	Board board;
	board.makeMove(0, 0, X);
	DO_CHECK(board.getCage(0, 0) == X);
}

void BoardTest::test_makeMove2() {
	Board board;
	board.makeMove(5, 5, O);
	DO_CHECK(board.canMove(5, 5, X) == 0);
}

void BoardTest::test_makeMove3() {
	Board board;
	board.makeMove(9, 9, O);
	DO_CHECK(board.canMove(5, 5, X) == 1);
}

void BoardTest::test_isWin1() {
	Board board;
	board.makeMove(9, 9, X);
	board.makeMove(9, 3, O);
	board.makeMove(9, 2, X);
	DO_CHECK(board.isWin() == GAME_IN_PROGRESS);
}

void BoardTest::test_isWin2() {
	Board board;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			board.makeMove(j, i, O);
		}
		board.makeMove(4, i, X);
		board.makeMove(5, i, X);
		for (int j = 6; j < 10; ++j) {
			board.makeMove(j, i, O);
		}
	}
	for (int j = 0; j < 4; ++j) {
		board.makeMove(j, 3, X);
	}
	board.makeMove(4, 3, O);
	board.makeMove(5, 3, O);
	for (int j = 6; j < 10; ++j) {
		board.makeMove(j, 3, X);
	}
	for (int i = 4; i < 7; ++i) {
		for (int j = 0; j < 4; ++j) {
			board.makeMove(j, i, O);
		}
		board.makeMove(4, i, X);
		board.makeMove(5, i, X);
		for (int j = 6; j < 10; ++j) {
			board.makeMove(j, i, O);
		}
	}
	for (int j = 0; j < 4; ++j) {
		board.makeMove(j, 7, X);
	}
	board.makeMove(4, 7, O);
	board.makeMove(5, 7, O);
	for (int j = 6; j < 10; ++j) {
		board.makeMove(j, 7, X);
	}
	for (int i = 8; i < 10; ++i) {
		for (int j = 0; j < 4; ++j) {
			board.makeMove(j, i, O);
		}
		board.makeMove(4, i, X);
		board.makeMove(5, i, X);
		for (int j = 6; j < 10; ++j) {
			board.makeMove(j, i, O);
		}
	}
	DO_CHECK(board.isWin() == DRAW);
}

void BoardTest::test_isWin3() {
	Board board;
	for (int i = 0; i < 5; ++i) {
		board.makeMove(3, 2 + i, X);
	}
	DO_CHECK(board.isWin() == X_WINS);
}

void BoardTest::test_isWin4() {
	Board board;
	for (int i = 0; i < 5; ++i) {
		board.makeMove(3 + i, i, O);
	}
	DO_CHECK(board.isWin() == O_WINS);
}

void BoardTest::test_isWin5() {
	Board board;
	for (int i = 0; i < 5; ++i) {
		board.makeMove(3 + i, i + 1, O);
	}
	DO_CHECK(board.isWin() == O_WINS);
}

void BoardTest::test_isWin6() {
	Board board;
	for (int i = 0; i < 5; ++i) {
		board.makeMove(3 + i,  8 - i, X);
	}
	DO_CHECK(board.isWin() == X_WINS);
}

void BoardTest::test_isWin7() {
	Board board;
	for (int i = 0; i < 4; ++i) {
		board.makeMove(3 + i,  8 - i, X);
	}
	DO_CHECK(board.isWin() == GAME_IN_PROGRESS);
}

void BoardTest::test_isWin8() {
	Board board;
	board.makeMove(0, 0, X);
	board.makeMove(1, 0, X);
	board.makeMove(2, 0, X);
	board.makeMove(3, 0, O);
	board.makeMove(4, 0, X);
	board.makeMove(5, 0, X);
	DO_CHECK(board.isWin() == GAME_IN_PROGRESS);
}
	
void BoardTest::test_getCage1() {
	Board board;
	board.makeMove(0, 0, X);
	DO_CHECK(board.getCage(0, 0) == X);
}

void BoardTest::test_getCage2() {
	Board board;
	board.makeMove(0, 0, X);
	DO_CHECK(board.getCage(0, 1) == EMPTY);
}

void BoardTest::test_getCage3() {
	Board board;
	board.makeMove(0, 7, O);
	DO_CHECK(board.getCage(0, 7) == O);
}

void BoardTest::test_getCage4() {
	Board board;
	DO_CHECK(board.getCage(0, 42) == WRONG_COORDINATE);
}

void BoardTest::runAllTests() {
	test_canMove1();
	test_canMove2();
	test_canMove3();
	
	test_makeMove1();
	test_makeMove2();
	test_makeMove3();

	test_isWin1();
	test_isWin2();
	test_isWin3();
	test_isWin4();
	test_isWin5();
	test_isWin6();
	test_isWin7();
	test_isWin8();
	
	test_getCage1();
	test_getCage2();
	test_getCage3();
	test_getCage4();
}

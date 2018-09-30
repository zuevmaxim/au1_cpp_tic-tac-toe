#include "BoardView.h"
#include <iostream>

View::View(Board *b) {
	board = b;
	turn = 0;
}

void View::showBoard() const {
	std::cout << '\n';
	for (int y = 0; y < BOARD_SIZE; ++y) {
		for (int x = 0; x < BOARD_SIZE; ++x) {
			switch (board->getCage(x, y)) {
				case X: std::cout << 'X'; break;
				case O: std::cout << 'O'; break;
				case EMPTY: std::cout << '.'; break;
				default: break; //no way to call wrong coordinate
			}
		}
		std::cout << '\n';
	}
} 

void View::doGameCycle(show_status show) {
	int x;
	int y;
	bool stop_game = 0;
	while (board->isWin() == GAME_IN_PROGRESS && !stop_game) {
		if (show == SHOW) {
			showBoard();
		}
		std::cout << (turn ? "X" : "O") << " move: ";
		std::cin >> y >> x;
		while (!board->makeMove(x, y, (turn ? X : O)) && !stop_game) {
			if (x == -1 && y == -1) {
				stop_game = 1;
			} else {
				std::cout << "Bad move!\n";
				std::cout << (turn ? "X" : "O") << " move: ";
				std::cin >> y >> x;
			}
		}
		turn = !turn; //change turn
	}
	if (!stop_game) {
		showBoard();
		switch (board->isWin()) {
			case X_WINS: std::cout << "X wins!\n"; break;
			case O_WINS: std::cout << "O wins!\n"; break;
			default : std::cout << "Draw.\n"; break;
		}
	}
}

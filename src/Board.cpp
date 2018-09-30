#include "Board.h"

Board::Board() {
	used_cages = 0;
	current_status = GAME_IN_PROGRESS;
	last_y = 0;
	last_x = 0;
	board = new cage* [BOARD_SIZE];
	for (int i = 0; i < BOARD_SIZE; ++i) {
		board[i] = new cage [BOARD_SIZE];
		for (int j = 0; j < BOARD_SIZE; ++j) {
			board[i][j] = EMPTY;
		}
	}
}

Board::~Board() {
	for (int i = 0; i < BOARD_SIZE; ++i) {
		delete [] board[i];
	}
	delete [] board;
}

bool Board::canMove(int x, int y, cage sign) const {
	if (x >= 0 && y >= 0 && x < BOARD_SIZE && y < BOARD_SIZE) {
		return board[y][x] == EMPTY;
	}
	return 0;
}

bool Board::makeMove(int x, int y, cage sign) {
	if (canMove(x, y, sign)) {
		++used_cages;
		board[y][x] = sign;
		last_y = y;
		last_x = x;
		checkGameStatus();
		return 1;
	}
	return 0;
}

cage Board::getCage(int x, int y) const {
	if (x >= 0 && y >= 0 && x < BOARD_SIZE && y < BOARD_SIZE) {
		return board[y][x];
	}
	return WRONG_COORDINATE;
}

bool Board::verticalCheck() const {
	int count_vertical = 0;
	cage sign = board[last_y][last_x];
	int tmp_y = last_y;
	while(tmp_y >= 0 && board[tmp_y][last_x] == sign) {
		++count_vertical;
		--tmp_y;
	}
	tmp_y = last_y + 1;
	while(tmp_y < BOARD_SIZE && board[tmp_y][last_x] == sign) {
		++count_vertical;
		++tmp_y;
	}
	return count_vertical >= WIN_POINTS;
}

bool Board::horizontalCheck() const {
	int count_horizontal = 0;
	cage sign = board[last_y][last_x];
	int tmp_x = last_x;
	while(tmp_x >= 0 && board[last_y][tmp_x] == sign) {
		++count_horizontal;
		--tmp_x;
	}
	tmp_x = last_x + 1;
	while(tmp_x < BOARD_SIZE && board[last_y][tmp_x] == sign) {
		++count_horizontal;
		++tmp_x;
	}
	return count_horizontal >= WIN_POINTS;
}

bool Board::diagonal1Check() const {
	int count_diagonal1 = 0;
	cage sign = board[last_y][last_x];
	int tmp_x = last_x;
	int tmp_y = last_y;
	while(tmp_x >= 0 && tmp_y >= 0 && board[tmp_y][tmp_x] == sign) {
		++count_diagonal1;
		--tmp_x;
		--tmp_y;
	}
	tmp_x = last_x + 1;
	tmp_y = last_y + 1;
	while(tmp_x < BOARD_SIZE && tmp_y < BOARD_SIZE && board[tmp_y][tmp_x] == sign) {
		++count_diagonal1;
		++tmp_x;
		++tmp_y;
	}
	return count_diagonal1 >= WIN_POINTS;
}

bool Board::diagonal2Check() const {
	int count_diagonal2 = 0;
	cage sign = board[last_y][last_x];
	int tmp_x = last_x;
	int tmp_y = last_y;
	while(tmp_x < BOARD_SIZE && tmp_y >= 0 && board[tmp_y][tmp_x] == sign) {
		++count_diagonal2;
		++tmp_x;
		--tmp_y;
	}
	tmp_x = last_x - 1;
	tmp_y = last_y + 1;
	while(tmp_x >= 0 && tmp_y < BOARD_SIZE && board[tmp_y][tmp_x] == sign) {
		++count_diagonal2;
		--tmp_x;
		++tmp_y;
	}
	return count_diagonal2 >= WIN_POINTS;
}

bool Board::drawCheck() const {
	return used_cages == BOARD_SIZE * BOARD_SIZE;
}

status Board::isWin() const {
	return current_status;
}

void Board::checkGameStatus() {
	cage last = board[last_y][last_x];
	if (current_status != GAME_IN_PROGRESS || last == EMPTY) {
		return;
	}

	bool win = verticalCheck() | horizontalCheck() | diagonal1Check() | diagonal2Check();
	if (win) {
		if (last == X) {
			current_status = X_WINS;
		} else {
			current_status = O_WINS;
		}
	} else if (drawCheck()) {
		current_status = DRAW;
	}
}


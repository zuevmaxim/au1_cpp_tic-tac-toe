#ifndef _BOARD_H_
#define _BOARD_H_ 

enum status {GAME_IN_PROGRESS, DRAW, X_WINS, O_WINS};
enum cage {X, O, EMPTY, WRONG_COORDINATE};
const int BOARD_SIZE = 10;
const int WIN_POINTS = 5;

class  Board {
private:
	status current_status;
	int used_cages;
	int last_x; 
	int last_y;
	cage** board;
	bool verticalCheck() const;
	bool horizontalCheck() const;
	bool diagonal1Check() const;
	bool diagonal2Check() const;
	bool drawCheck() const;
	void checkGameStatus();

public:
	Board();
	~Board();
	bool canMove(int x, int y, cage sign) const;
    bool makeMove(int x, int y, cage sign);
	status isWin() const;
    cage getCage(int x, int y) const;
};

#endif

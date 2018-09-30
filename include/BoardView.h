#ifndef _VIEW_H_
#define _VIEW_H_ 

#include "Board.h"

enum show_status {SHOW, DO_NOT_SHOW};

class View {
private:
	Board *board;
	bool turn;
public:
    View(Board *b);
    void showBoard() const; 
    void doGameCycle(show_status show);
};

#endif

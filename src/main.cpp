#include "BoardView.h"
#include <string.h>

int main(int argc, char* argv[]) {
	Board board;
	View view(&board);
	if (argc >= 2 && strcmp(argv[1], "silent") == 0) {
		view.doGameCycle(DO_NOT_SHOW);
	} else {
		view.doGameCycle(SHOW);
	}
}

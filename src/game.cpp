#include "game.hpp"
#include <iostream>

bool Game::make_move(int i, int j) {
	if (!gameboard.validMove(i, j)) {
		return false;
	}
	gameboard.popBubble(i, j);
	return true;
}

void Game::console_dump() {
	int rows = gameboard.rows();
	int columns = gameboard.columns();

	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < columns; c++) {
			cout << gameboard(r, c) << " ";
		}
		cout << endl;
	}
}

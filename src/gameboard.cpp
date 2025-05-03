#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "gameboard.hpp"


// PRIVATE FUNCTIONS
/* ------------------- */
void GameBoard::fall(int istart, int j) {
	pop_criteria = 3;
	int i = istart;
	int n = board.size();

	while (i < n - 1 && board[i + 1][j] == 0) {
		swap(board[i][j], board[i + 1][j]);
		i++;
	}
}

bool GameBoard::countAdjacent(int i, int j, int color, int count, int criteria) {

}


// TODO: Implement me
bool GameBoard::validMove(int i, int j) {
	int count = 0;
	return false;
}

bool GameBoard::selectCell(int i, int j) {
	if (!validMove(i, j)) {
		return false;
	}
	return true;
}

// PUBLIC FUNCTIONS
/* ------------------- */
GameBoard::GameBoard(int rows, int cols) {
	this->rows = rows;
	this->columns = cols;
	srand(time(NULL));
	board = vector<vector<int>>(rows, vector<int>(cols));
	for(vector<int>& row : board) {
		for(int& element : row) {
			element = rand() % 4;
		}
	}
}

void GameBoard::dump() {
	for (vector<int>& row : board) {
		for (int& element : row) {
			cout << element << " ";
		}
		cout << endl;
	}
}

void GameBoard::gravity() {
	int n = board.size();
	int m = board[0].size();

	// going column by column
	for(int j = 0; j < m; j++) {
		for (int i = n - 1; i >= 0; i--) {
			fall(i, j);
		}
	}
}

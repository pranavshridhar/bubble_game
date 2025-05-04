#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>


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
	pop_criteria = 3; // FIXME: Just for starters. Change later on.
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

void GameBoard::_cell_counter(int i, int j, vector<vector<bool>>& map, int& count, int target) {

	// Base cases: in this EXACT order to avoid segfault
	if ((i < 0 || i >= columns) || (j < 0 || j >= rows) ) return; // current position is out of bounds
	if (count >= pop_criteria) return; // we have all we need
	if (board[i][j] != target) return; // this is not a cell to pop
	if (map[i][j] == true) return; // if we have already visited cell

	// mark this cell as visited
	map[i][j] = true;
	count++;

	_cell_counter(i+1, j, map, count, target);
	_cell_counter(i-1, j, map, count, target);
	_cell_counter(i, j+1, map, count, target);
	_cell_counter(i, j-1, map, count, target);

}


bool GameBoard::validMove(int i, int j, int target) {
	// make the map
	vector<vector<bool>> visit_map (
		rows, vector<bool>(columns, false)
	);

	int count = 0;

	_cell_counter(i, j, visit_map, count, target);

	return count >= pop_criteria;
}
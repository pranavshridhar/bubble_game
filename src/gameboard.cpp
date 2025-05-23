#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>

#include "gameboard.hpp"
#include "utilities/out_of_bounds.hpp"


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


void GameBoard::_popper(int i, int j, int target) {
	if ( (i < 0 || i >= _rows) || 
		(j < 0 || j >= _columns) 
	) return;

	if (board[i][j] != target) return;

	board[i][j] = 0;

	_popper(i+1, j, target);
	_popper(i-1, j, target);
	_popper(i, j+1, target);
	_popper(i, j-1, target);
	
}

// PUBLIC FUNCTIONS
/* ------------------- */
GameBoard::GameBoard(int rows, int cols)
 : GameBoard(rows, cols, time(nullptr)) {}

GameBoard::GameBoard(int rows, int cols, unsigned int seed) : _rows(rows), _columns(cols) {
	pop_criteria = 3; // FIXME: Just for starters. Change later on.
	srand(seed);
	board = vector<vector<int>>(rows, vector<int>(cols));
	for(vector<int>& row : board) {
		for(int& element : row) {
			element = (rand() % 4) + 1;
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
	if ((i < 0 || i >= _rows) || (j < 0 || j >= _columns) ) return; // current position is out of bounds
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


bool GameBoard::validMove(int i, int j) {
	if (
		i >= _rows || i < 0 ||
		j >= _columns || j < 0
	) {
		throw OutOfBoundsException(i, j);
	}

	int target = board[i][j];
	vector<vector<bool>> visit_map (
		_rows, vector<bool>(_columns, false)
	);

	int count = 0;

	_cell_counter(i, j, visit_map, count, target);

	return count >= pop_criteria;
}

void GameBoard::popBubble(int i, int j) {
	// Precondition: validmove(i, j) is true
	// TODO: Throw an exception otherwise
	// TODO: Make this count how many cells are being popped
	int target = board[i][j];
	_popper(i, j, target);

}

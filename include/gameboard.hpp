#pragma once
#include <vector>
using namespace std; // FIXME: Take this away in later builds

class GameBoard {
private:

	int pop_criteria;
	const int _rows;
	const int _columns;
	vector<vector<int>> board;

	void fall(int istart, int j);
	// bool validMove(int i, int j);
	void _cell_counter(int i, int j, vector<vector<bool>>& map, int& count, int target);

	void _popper(int i, int j, int target);

public:

	// Constructs a rows x cols gameboard, all with random values
	GameBoard(int rows, int cols);

	GameBoard(int rows, int cols, unsigned int seed);

	// Retrieves the number of rows in the GameBoard
	int rows() const { return _rows; }

	// Retrieves the number of columns in the GameBoard
	int columns() const { return _columns; }

	// This is GameBoard() operator
	int& operator() (int i, int j) {
		return board[i][j];
	}

	// Prints the whole gameboard to the screen
	void dump();

	// Makes all the cells fall down
	void gravity();

	// Checker to see if the cell is allowed to be popped
	bool validMove(int i, int j);

	void popBubble(int i, int j);
 
};
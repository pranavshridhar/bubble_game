#pragma once
#include <vector>
using namespace std; // FIXME: Take this away in later builds

class GameBoard {
private:

	int pop_criteria;
	int rows;
	int columns;
	vector<vector<int>> board;

	void fall(int istart, int j);
	// bool validMove(int i, int j);
	void _cell_counter(int i, int j, vector<vector<bool>>& map, int& count, int target);

public:

	// Constructs a rows x cols gameboard, all with random values
	GameBoard(int rows, int cols);

	GameBoard(int rows, int cols, unsigned int seed);

	// Prints the whole gameboard to the screen
	void dump();

	// Makes all the cells fall down
	void gravity();

	bool selectCell(int i, int j);

	int& operator()(int i, int j) {
		return board[i][j];
	}

	bool validMove(int i, int j);

};
#pragma once
#include <vector>
using namespace std; // FIXME: Take this away in later builds

class GameBoard {
private:

	struct Position {
		int i;
		int j;
		Position(int rows, int cols) : i(rows), j(cols) {}
	};

	int pop_criteria;
	int rows;
	int columns;
	vector<vector<int>> board;

	void fall(int istart, int j);
	bool validMove(int i, int j);

public:

	// Constructs a rows x cols gameboard, all with random values
	GameBoard(int rows, int cols);

	// Prints the whole gameboard to the screen
	void dump();

	// Makes all the cells fall down
	void gravity();

	bool selectCell(int i, int j);

	int& operator()(int i, int j) {
		return board[i][j];
	}

};
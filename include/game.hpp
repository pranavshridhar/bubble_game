#pragma once
#include "gameboard.hpp"
using namespace std;

class Game {
private:
	GameBoard gameboard;
	int moves = 0;

public:

	// ===============
	//  Constructors
	// ===============

	// Initializes a 7x10 board by default
	Game() : gameboard(GameBoard(7, 10)) {};
	Game(int rows, int cols) : gameboard(GameBoard(rows, cols)) {};
	Game(int rows, int cols, unsigned int seed) : gameboard( GameBoard(rows, cols, seed)) {};


	bool make_move(int i, int j);

	void apply_gravity() {
		gameboard.gravity();
	};

	void console_dump();

	~Game() {
		cout << "Game object commited suicide" << endl;
	}



};
#pragma once
#include "gameboard.hpp"
#include <iostream>
using namespace std;

class Game {
private:
    int _rows;
    int _columns;
    GameBoard gameboard;

public:
    // ===============
    //  Constructors
    // ===============

    // Initializes a 7x10 board by default
    Game()
			: _rows(7), _columns(10), gameboard(GameBoard(7, 10)) {}

    Game(int rows, int cols)
			: _rows(rows), _columns(cols), gameboard(GameBoard(rows, cols)) {}

    Game(int rows, int cols, unsigned int seed)
      : _rows(rows), _columns(cols), gameboard(GameBoard(rows, cols, seed)) {}

    int rows() const {return _rows;}

    int columns() const {return _columns;}

    bool make_move(int i, int j);

    void apply_gravity() {
			gameboard.gravity();
    }

    void console_dump();

    ~Game() {}
};

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "gameboard.hpp"

GameBoard::GameBoard(int rows, int cols) {
  board = vector<vector<int>>(rows, vector<int>(cols));
}

void GameBoard::dump() {
  for (vector<int>& row : this->board) {
    for (int& element : row) {
      cout << element << " ";
    }
    cout << endl;
  }
}
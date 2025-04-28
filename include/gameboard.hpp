#pragma once
#include <vector>

using namespace std;

class GameBoard {
private:
  vector<vector<int>> board;
  void fall(int istart, int j);

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
#pragma once
#include <vector>

using namespace std;

class GameBoard {
private:
  vector<vector<int>> board;

public:
  GameBoard(int rows, int cols);
  void dump();

};
#pragma once
#include <vector>

using namespace std;

class GameBoard {
private:
  vector<vector<int>> board;
  void fall(int istart, int j);

public:
  GameBoard(int rows, int cols);
  void dump();
  int& operator()(int i, int j);
  void gravity();
  bool selectCell(int i, int j);

};
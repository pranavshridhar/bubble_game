#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "gameboard.hpp"

GameBoard::GameBoard(int rows, int cols) {
  board = vector<vector<int>>(rows, vector<int>(cols));
	for(vector<int>& row : board) {
    for(int& element : row) {
      element = rand() % 4;
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

void GameBoard::fall(int istart, int j) {
  int i = istart;
  int n = board.size();

  while (i < n - 1 && board[i + 1][j] == 0) {
    swap(board[i][j], board[i + 1][j]);
    i++;
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

bool GameBoard::selectCell(int i, int j) {
  return false;
}
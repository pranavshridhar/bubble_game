#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

vector<vector<int>> generate_board(int rows, int columns) {
  srand(time(0));

  vector<vector<int>> board(rows);
  for(vector<int>& row : board) {
    row = vector<int>(columns);
  }


  for(vector<int>& row : board) {
    for(int& element : row) {
      element = rand() % 4;
    }
  }

  return board;

}

void fall(vector<vector<int>>& board, int istart, int j) {
  int i = istart;
  int n = board.size();

  while (i < n - 1 && board[i + 1][j] == 0) {
    swap(board[i][j], board[i + 1][j]);
    i++;
  }
}

void gravity(vector<vector<int>>& board) {

  int n = board.size();
  int m = board[0].size();

  // going column by column
  for(int j = 0; j < m; j++) {
    for (int i = n - 1; i >= 0; i--) {
      fall(board, i, j);
    }
  }
}

int main() {

  vector<vector<int>> board = generate_board(7, 10);

  cout << "GENERATED BOARD" << endl;
  for(vector<int>& row : board) {
    for(int& element : row) {
      cout << element << " ";
    }
    cout << endl;
  }
  cout << endl;

  gravity(board);
  cout << "Gravitified board" << endl;
  for(vector<int>& row : board) {
    for(int& element : row) {
      cout << element << " ";
    }
    cout << endl;
  }

}
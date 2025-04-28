#include <iostream>
#include <unistd.h>
#include "gameboard.hpp"

using namespace std;

int main() {

	GameBoard board(7, 10);
	cout << "------ GENERATED BOARD ------" << '\n';
	board.dump();
	cout << endl;

	board.gravity();
	cout << "------ GRAVITIFIED BOARD ------" << '\n';
	board.dump();
	cout << endl;

	return 0;

}
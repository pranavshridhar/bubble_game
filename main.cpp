#include <iostream>
#include <unistd.h>
#include "gameboard.hpp"

using namespace std;

int main() {

	GameBoard board(7, 10, 1746386351);
	cout << "------ GENERATED BOARD ------" << '\n';
	board.dump();
	cout << endl;

	cout << "Is i=6 and i=8 a valid move?" << endl;
	if (board.validMove(6, 8)) {
		cout << "Yes it is!" << endl;
	}
	cout << endl;

	board.popBubble(6, 8);
	cout << "------ AIRY BOARD ------" << '\n';
	board.dump();


	board.gravity();
	cout << "------ GRAVITIFIED BOARD ------" << '\n';
	board.dump();
	cout << endl;

	return 0;

}
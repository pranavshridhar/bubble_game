#include <iostream>
#include <unistd.h>
#include <csignal>
#include <atomic>
#include "gameboard.hpp"
#include "game.hpp"
#include "utilities/out_of_bounds.hpp"
using namespace std;

atomic<bool> running(true);

void signal_handler(int signum) {
	cout << "Exiting..." << endl;
	exit(0);
}

int main() {

	signal(SIGINT, signal_handler);

	// GameBoard board(7, 10, 1746386351);
	Game game(7, 10, 1746386351);
	cout << " ********* Welcome to the game ********* " << endl;
	cout << endl;

	cout << endl << endl;

	while (true) {
		game.console_dump();
		cout << "Input row and column (in that order, zero indexed, separated by space) > ";
		int row, column;
		cin >> row >> column;

		try {
			if (!game.make_move(row, column)) {
				cout << "This move cannot be made. Please select another cell." << endl;
			}
			game.apply_gravity();
		} catch (const OutOfBoundsException& e) {
			cout << e.what() << endl;
		}

		cout << endl;
	}


	return 0;

}
#include <iostream>
#include <unistd.h>
#include <csignal>
#include "gameboard.hpp"
#include "game.hpp"
#include <utilities/out_of_bounds.hpp>
using namespace std;

atomic<bool> running(true);

void signal_handler(int signum) {
	cout << "I got interrupted" << endl;
	running = false;
}

bool input_available() {
	fd_set fds;
	FD_ZERO(&fds);
	FD_SET(STDIN_FILENO, &fds);
	timeval timeout = {1, 0};  // 1 second
	return select(STDIN_FILENO + 1, &fds, nullptr, nullptr, &timeout) > 0;
}

int main() {

	signal(SIGINT, signal_handler);

	// GameBoard board(7, 10, 1746386351);
	Game game(7, 10, 1746386351);
	cout << " ********* Welcome to the game ********* " << endl;
	cout << endl;

	cout << endl << endl;

	while (running) {
		game.console_dump();
		cout << "Input row and column (in that order, zero indexed, separated by space) > ";
		int row, column;
		cin >> row >> column;

		if (!input_available()) {
			continue;
		}

		try {
			if (!game.make_move(row, column)) {
				cout << "This move cannot be made. Please select another cell." << endl;
			}
		} catch (const OutOfBoundsException& e) {
			cout << e.what() << endl;
		}
	}


	return 0;

}
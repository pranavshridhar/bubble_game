#include <iostream>
#include <unistd.h>
#include <csignal>
#include "gameboard.hpp"
#include "game.hpp"

using namespace std;

atomic<bool> running(true);

void signal_handler(int signum) {
	cout << "I got interrupted" << endl;
	running = false;
}

int main() {

	signal(SIGINT, signal_handler);

	// GameBoard board(7, 10, 1746386351);
	Game game(7, 10, 1746386351);
	cout << " ********* Welcome to the game ********* " << endl;
	cout << endl;

	game.console_dump();

	cout << endl;

	while (running) {
		cout << "This mofo is running" << endl;
		sleep(1);
	}


	return 0;

}
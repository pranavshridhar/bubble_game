#include "game.hpp"

bool Game::make_move(int i, int j) {
  return gameboard.validMove(i, j);
}

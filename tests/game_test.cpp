#include <gtest/gtest.h>
#include "game.hpp"


TEST(GameTest, SizeTest) {
	Game gb(7, 10);
	EXPECT_EQ(7, gb.rows());
	EXPECT_EQ(10, gb.columns());
}

TEST(GameTest, MoveCountTest) {
	Game g(7, 10, 1746386351);
	vector<pair<int, int>> test_moves {
		{0, 7}, {5, 0}, {0, 5}, {4, 3}, {4, 2}, {5, 3}, {5, 6}, {5, 9}
	};

	for (const auto& move : test_moves) {
		EXPECT_TRUE(g.make_move(move.first, move.second));
		g.apply_gravity();
	}
	EXPECT_EQ(test_moves.size(), g.moves());
}
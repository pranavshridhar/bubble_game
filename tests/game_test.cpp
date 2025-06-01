#include <gtest/gtest.h>
#include "game.hpp"


TEST(GameTest, SizeTest) {
    Game gb(7, 10);
    EXPECT_EQ(7, gb.rows());
    EXPECT_EQ(10, gb.columns());
}
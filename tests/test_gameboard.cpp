#include <gtest/gtest.h>
#include "gameboard.hpp"


TEST(GameBoardTest, SizeTest) {
    GameBoard gb(7, 10);
    EXPECT_EQ(7, gb.rows());
    EXPECT_EQ(10, gb.columns());

}

TEST(GameBoardTest, MoveValidity) {
    GameBoard gb(7, 10, 1746386351);

    EXPECT_TRUE( gb.validMove(6, 3) );
    EXPECT_TRUE( gb.validMove(0, 4) );

    EXPECT_FALSE( gb.validMove(0, 0) );

}
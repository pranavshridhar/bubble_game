#include <gtest/gtest.h>
#include "gameboard.hpp"
#include "utilities/out_of_bounds.hpp"


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

    EXPECT_THROW( gb.validMove(-1, -1), OutOfBoundsException);
}

TEST(GameBoardTest, OutOfBoundsTest) {
    GameBoard gb(7, 10);
    EXPECT_THROW( gb.validMove(-1, -1), OutOfBoundsException);
    EXPECT_THROW( gb.validMove(7, 10), OutOfBoundsException);

    EXPECT_NO_THROW( gb.validMove(0, 0));
    EXPECT_NO_THROW( gb.validMove(6, 9));
}
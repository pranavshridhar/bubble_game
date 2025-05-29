#include <gtest/gtest.h>
#include "gameboard.hpp"
#include "utilities/out_of_bounds.hpp"
#include "utilities/invalid_move.hpp"


TEST(GameBoardTest, SizeTest) {
    GameBoard gb(7, 10);
    EXPECT_EQ(7, gb.rows());
    EXPECT_EQ(10, gb.columns());

}

TEST(GameBoardTest, MoveValidity) {
    GameBoard gb(7, 10, 1746386351);

    EXPECT_TRUE( gb.validMove(6, 3) );
    EXPECT_TRUE( gb.validMove(0, 3) );
    EXPECT_FALSE( gb.validMove(3, 0) );
    EXPECT_FALSE( gb.validMove(6, 9) );

    EXPECT_THROW( gb.validMove(-1, -1), OutOfBoundsException);
}

TEST(GameBoardTest, OutOfBoundsTest) {
    GameBoard gb(7, 10);
    EXPECT_THROW( gb.validMove(-1, -1), OutOfBoundsException);
    EXPECT_THROW( gb.validMove(7, 10), OutOfBoundsException);

    EXPECT_NO_THROW( gb.validMove(0, 0));
    EXPECT_NO_THROW( gb.validMove(6, 9));
}

// TODO: Expand on this, make popping more testable.
TEST(GameBoardTest, PopTest) {
    // Test for exceptions first
    GameBoard gb(7, 10, 1746386351);

    EXPECT_THROW( gb.popBubble(-1, -1), OutOfBoundsException);
    EXPECT_THROW( gb.popBubble(7, 10), OutOfBoundsException);
    EXPECT_THROW( gb.popBubble(0, 4), InvalidMoveException);
    EXPECT_THROW( gb.popBubble(6, 5), InvalidMoveException);

}

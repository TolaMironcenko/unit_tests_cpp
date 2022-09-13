#include <iostream>
#define CATCH_CONFIG_MAIN
#include "lib/catch.hpp"

int Square(int value)
{
    return value * value;
}

TEST_CASE("Squares are computed", "[Square]")
{
    REQUIRE(Square(1) == 1);
    REQUIRE(Square(2) == 4);
    REQUIRE(Square(3) == 9);
    REQUIRE(Square(7) == 49);
    REQUIRE(Square(10) == 100);
}
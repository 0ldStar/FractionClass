#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include <iostream>
#include "Fraction.h"
#include <iostream>
TEST_CASE("Squares are computed", "[Square]")
{
    REQUIRE(1 == 1);
}
int main(int argc, char* argv[] ) {
    Catch::Session().run( argc, argv );
    Fraction a(11, 33);
    Fraction b (-1, 4);
    Fraction c (1, 2);
    a = b / c;
    Fraction d(a);
    std::cout << a.getStr();
    return 0;
}


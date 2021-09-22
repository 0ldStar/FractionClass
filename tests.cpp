//
// Created by 777 on 10.09.2021.
//
#include "catch.hpp"
#include "Fraction.h"

TEST_CASE("Fractions class is worked", "[Square]")
{
    using namespace std;
    Fraction a(11, 33);
    Fraction b(-1, 4);
    Fraction c(1, 2);
    REQUIRE(strcmp("1/3", a.getStr()) == 0);
    REQUIRE(strcmp("-1/4", b.getStr()) == 0);
    REQUIRE(strcmp("1/2", c.getStr()) == 0);
    REQUIRE(0.5f == (float) c);
    a = b / c;
    REQUIRE(strcmp("-1/2", a.getStr()) == 0);
    a = b * c;
    REQUIRE(strcmp("-1/8", a.getStr()) == 0);
    a = b + c;
    REQUIRE(strcmp("1/4", a.getStr()) == 0);
    a = b - c;
    REQUIRE(strcmp("-3/4", a.getStr()) == 0);
    Fraction d;
    d = a;
    a = b;
    REQUIRE(strcmp("-3/4", d.getStr()) == 0);

}
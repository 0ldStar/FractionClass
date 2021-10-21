//
// Created by 777 on 05.10.2021.
//
#include "gtest/gtest.h"
#include "../Fraction.h"
#include <iostream>

#include <fstream>

TEST(lab1, constructorTests) {

    Fraction a(11, 33);
    Fraction b(-1, 4);
    Fraction c(1, 2);
    Fraction d;

    ASSERT_THROW(Fraction e(1, 0), exception);
    ASSERT_STREQ(a.getStr(), "1/3");
    ASSERT_STREQ(b.getStr(), "-1/4");
    ASSERT_STREQ(c.getStr(), "1/2");

    d = a;
    a = b;
    ASSERT_STREQ(d.getStr(), "1/3");
}


TEST(lab2, castTest) {
    Fraction a(1, 2);
    ASSERT_EQ(0.5f, (float) a);
}

TEST(lab2, arifmeticOperationTests) {

    Fraction a(11, 33);
    Fraction b(-1, 4);
    Fraction c(1, 2);
    Fraction d(0, 1);

    a = b / c;
    ASSERT_STREQ(a.getStr(), "-1/2");
    a = b * c;
    ASSERT_STREQ(a.getStr(), "-1/8");
    a = b + c;
    ASSERT_STREQ(a.getStr(), "1/4");
    a = b - c;
    ASSERT_STREQ(a.getStr(), "-3/4");

    ASSERT_THROW(a / d, exception);
}
//
// Created by 777 on 05.10.2021.
//
#include "gtest/gtest.h"
#include "../Fraction.h"
#include "../CompleteFracion.h"
#include "../MixedFractions.h"
#include <iostream>

#include <fstream>

TEST(lab1, constructorTests) {

    Fraction a(11, 33);
    Fraction b(-1, 4);
    Fraction c(1, 2);
    Fraction d;

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

    a = b / c;
    ASSERT_STREQ(a.getStr(), "-1/2");
    a = b * c;
    ASSERT_STREQ(a.getStr(), "-1/8");
    a = b + c;
    ASSERT_STREQ(a.getStr(), "1/4");
    a = b - c;
    ASSERT_STREQ(a.getStr(), "-3/4");
}

TEST(lab3, fileSteamTest) {
    Fraction a(3, 4);
    Fraction b(3, 5);
    Fraction c;
    ofstream fileOut;

    fileOut.open("../write.txt");
    if (!fileOut.is_open()) {
        std::cerr << "fileOut open failed: " << std::strerror(errno) << "\n";
        ASSERT_TRUE(0);
    }
    fileOut << a << endl;
    fileOut << b << endl;
    fileOut.close();

    ifstream fileIn("../write.txt");
    if (!fileIn.is_open()) {
        std::cerr << "fileOut open failed: " << std::strerror(errno) << "\n";
        ASSERT_TRUE(0);
    }
    fileIn >> c;
    ASSERT_TRUE(!strcmp(a.getStr(), c.getStr()));
    fileIn >> c;
    ASSERT_TRUE(!strcmp(b.getStr(), c.getStr()));
    fileIn.close();
}


TEST(lab4, CompleteFractionsConstructorTests) {

    CompleteFracion a(11, 33);
    CompleteFracion b(-1, 4);
    CompleteFracion c(1, 2);
    CompleteFracion d;

    ASSERT_STREQ(a.getStr(), "1/3");
    ASSERT_STREQ(b.getStr(), "-1/4");
    ASSERT_STREQ(c.getStr(), "1/2");

    d = a;
    a = b;
    ASSERT_STREQ(d.getStr(), "1/3");
}


TEST(lab4, CompleteFractionsResultTest) {
    CompleteFracion a(1, 2);
    CompleteFracion b(1, 3);

    ASSERT_EQ(a.getRes(), 0.5);
    ASSERT_DOUBLE_EQ(b.getRes(), (double) 1 / 3);
}

TEST(lab4, MixedFractionsConstructorTests) {

    MixedFractions a(1, 11, 33);
    MixedFractions b(2, -1, 4);
    MixedFractions c(-3, 1, 2);
    MixedFractions d;

    ASSERT_STREQ(a.getStr(), "1|1/3");
    ASSERT_STREQ(b.getStr(), "2|-1/4");
    ASSERT_STREQ(c.getStr(), "-3|1/2");
    d = a;
    a = b;
    ASSERT_TRUE(!strcmp("1|1/3", d.getStr()));
}


TEST(laba4, MixedFractionsArifmeticOperationsTests) {
    MixedFractions a;
    MixedFractions b(2, -1, 4);
    MixedFractions c(-3, 1, 2);

    a = b / c;
    ASSERT_STREQ(a.getStr(), "|-7/10");
    a = b * c;
    ASSERT_STREQ(a.getStr(), "-4|3/8");
    a = b + c;
    ASSERT_STREQ(a.getStr(), "|-3/4");
    a = b - c;
    ASSERT_STREQ(a.getStr(), "4|1/4");
}

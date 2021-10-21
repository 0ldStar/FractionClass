//
// Created by 777 on 05.10.2021.
//
#include "gtest/gtest.h"
#include "../Fraction.h"
#include "../CompleteFracion.h"
#include "../MixedFractions.h"
#include "../List.h"
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

    ofstream binOut("../readFromBinary.dat", ios::out | ios::binary | ios::app);
    if (!binOut.is_open()) {
        std::cerr << "binOut open failed: " << std::strerror(errno) << "\n";
        ASSERT_TRUE(0);
    }
    a.writeInBinary(binOut);
    b.writeInBinary(binOut);
    binOut.close();
    ifstream binIn("../readFromBinary.dat", ios::in | ios::binary);
    if (!binIn.is_open()) {
        std::cerr << "binIn open failed: " << std::strerror(errno) << "\n";
        ASSERT_TRUE(0);
    }
    c.readFromBinary(binIn);
    ASSERT_TRUE(!strcmp(a.getStr(), c.getStr()));
    c.readFromBinary(binIn);
    ASSERT_TRUE(!strcmp(b.getStr(), c.getStr()));
    binIn.close();
}


TEST(lab4, CompleteFractionsConstructorTests) {

    CompleteFracion a(11, 33);
    CompleteFracion b(-1, 4);
    CompleteFracion c(1, 2);
    CompleteFracion d;

    ASSERT_THROW(CompleteFracion e(1, 0), exception);
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

    ASSERT_THROW(MixedFractions e(1, 1, 0), exception);
    ASSERT_STREQ(a.getStr(), "1|1/3");
    ASSERT_STREQ(b.getStr(), "2|-1/4");
    ASSERT_STREQ(c.getStr(), "-3|1/2");
    d = a;
    a = b;
    ASSERT_TRUE(!strcmp("1|1/3", d.getStr()));
}


TEST(lab4, MixedFractionsArifmeticOperationsTests) {
    MixedFractions a;
    MixedFractions b(2, -1, 4);
    MixedFractions c(-3, 1, 2);
    MixedFractions d(-3, 0, 2);


    a = b / c;
    ASSERT_STREQ(a.getStr(), "|-7/10");
    a = b * c;
    ASSERT_STREQ(a.getStr(), "-4|3/8");
    a = b + c;
    ASSERT_STREQ(a.getStr(), "|-3/4");
    a = b - c;
    ASSERT_STREQ(a.getStr(), "4|1/4");

    ASSERT_THROW(a / d, exception);
}

TEST(lab5, stackTest) {
    List List;
    Fraction a(1, 3);
    Fraction b(1, 6);
    MixedFractions c(1, 1, 6);
    MixedFractions d(-3, 1, 7);
    CompleteFracion e(5, 7);
    CompleteFracion f(9, 27);
    List.pushFront(a);
    List.pushFront(b);
    List.pushFront(c);
    List.pushFront(d);
    List.pushFront(e);
    List.pushFront(f);
    ASSERT_STREQ(List[0].getStr(), "1/3");
    ASSERT_STREQ(List[1].getStr(), "5/7");
    ASSERT_STREQ(List[2].getStr(), "-3|1/7");
    ASSERT_STREQ(List[3].getStr(), "1|1/6");
    ASSERT_STREQ(List[4].getStr(), "1/6");
    ASSERT_STREQ(List[5].getStr(), "1/3");
}

TEST(lab5, listCorrectWorkCheck) {
    List list;
    list.popFront();
    ASSERT_THROW(list[1], exception);
}

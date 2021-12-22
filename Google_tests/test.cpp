//
// Created by 777 on 05.10.2021.
//
#include "gtest/gtest.h"
#include "../Fraction.h"
#include "../CompleteFracion.h"
#include "../MixedFractions.h"
#include "../List.h"
#include <iostream>
#include <queue>
#include <map>
#include <ctime>
#include <set>

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

    ofstream binIn("../binaryIn.dat", ios::binary);
    if (!binIn.is_open()) {
        std::cerr << "binIn open failed: " << std::strerror(errno) << "\n";
        ASSERT_TRUE(0);
    }
    binIn << a << endl;
    binIn << b << endl;
    binIn.close();

    ifstream binOut("../binaryIn.dat", ios::binary);
    if (!binOut.is_open()) {
        std::cerr << "binOut open failed: " << std::strerror(errno) << "\n";
        ASSERT_TRUE(0);
    }
    binOut >> c;
    ASSERT_TRUE(!strcmp(a.getStr(), c.getStr()));
    binOut >> c;
    ASSERT_TRUE(!strcmp(b.getStr(), c.getStr()));
    binOut.close();
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

TEST(lab5, FractionStackTest) {
    List<Fraction> List;
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

TEST(lab7, IntStackTest) {
    List<int> intList;
    int num1 = 1;
    int num2 = 2;
    intList.pushFront(num1);
    intList.pushFront(num2);
    ASSERT_EQ(intList[0], 2);
    ASSERT_EQ(intList[1], 1);
}

TEST(lab7, CharStackTest) {
    List<char> charList;
    char char1 = 'a';
    char char2 = 'b';
    charList.pushFront(char1);
    charList.pushFront(char2);
    ASSERT_EQ(charList[0], 'b');
    ASSERT_EQ(charList[1], 'a');
}

TEST(lab7, FloatStackTest) {
    List<float> floatList;
    float float1 = 1.1;
    float float2 = 2.2;
    floatList.pushFront(float1);
    floatList.pushFront(float2);
    ASSERT_FLOAT_EQ(floatList[0], 2.2);
    ASSERT_FLOAT_EQ(floatList[1], 1.1);
}

TEST(lab8, intQueue) {
    cout << "Queue" << endl;
    queue<int> q;
    q.push(1);
    ASSERT_EQ(q.front(), 1);
    q.push(2);
    q.pop();
    ASSERT_EQ(q.front(), 2);
    srand(time(nullptr));
    int start = clock();
    for (int i = 0; i < 10000; ++i) {
        q.push(rand() % 10000);
    }
    cout << "Add : " << clock() - start << endl;
    start = clock();
    while (!q.empty()) {
        q.pop();
    }
    cout << "Pop : " << clock() - start << endl;
}

TEST(lab8, intMap) {
    cout << "Map" << endl;
    map<int, int> m;
    m.insert(make_pair(1, 1));
    ASSERT_EQ(m[1], 1);
    srand(time(nullptr));
    int start = clock();
    for (int i = 0; i < 10000; ++i) {
        m.insert(make_pair(i, rand() % 10000));
    }
    cout << "Add : " << clock() - start << endl;
    start = clock();
    for (int i = 0; i < 10000; ++i) {
        m.find(i);
    }
    cout << "Find : " << clock() - start << endl;
    multiset<Fraction> multiset1;
    Fraction a(1, 2);
    multiset1.insert(a);
    multimap<Fraction, int> multimap1;
    multimap1.insert(make_pair(a, 1));
}

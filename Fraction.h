//
// Created by 777 on 09.09.2021.
//

#ifndef LABA3_1_5_FRACTION_H
#define LABA3_1_5_FRACTION_H

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Fraction {
public:
    Fraction();

    Fraction(Fraction &a);

    Fraction(Fraction const &b);

    Fraction(int numerator, int denominator);

    virtual char *getStr();

    friend Fraction operator+(const Fraction &left, const Fraction &right);

    friend Fraction operator-(const Fraction &left, const Fraction &right);

    friend Fraction operator*(const Fraction &left, const Fraction &right);

    friend Fraction operator/(const Fraction &left, const Fraction &right);

    friend ostream &operator<<(ostream &os, const Fraction &p);

    friend istream &operator>>(istream &is, Fraction &p);

    void readFromBinary(istream &is);

    void writeInBinary(ostream &os);

    Fraction &operator=(const Fraction &right);

    operator float() const;

    ~Fraction();

    static int NOK(int a, int b);

protected:
    void reduction();

    static int NOD(int a, int b);

    void strConstruct();

    static int countCalc(int num);

    int numerator;
    int denominator;
    char *str;

};


#endif //LABA3_1_5_FRACTION_H

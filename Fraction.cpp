//
// Created by 777 on 09.09.2021.
//

#include "Fraction.h"

#include <cmath>
#include <iostream>
#include <charconv>
#include <fstream>
#include <exception>

Fraction::Fraction() {
    this->numerator = 1;
    this->denominator = 1;
    this->str = nullptr;
}


Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0) throw std::exception();
    this->numerator = numerator;
    this->denominator = denominator;
    this->str = nullptr;
    Fraction::reduction();
    strConstruct();
}

Fraction::~Fraction() {
    delete[]this->str;
}

Fraction::Fraction(Fraction &a) {
    this->numerator = a.numerator;
    this->denominator = a.denominator;
    this->str = nullptr;
    strConstruct();
}

void Fraction::reduction() {
    int nod = Fraction::NOD(std::abs(numerator), std::abs(denominator));
    numerator /= nod;
    denominator /= nod;
}

Fraction operator-(const Fraction &left, const Fraction &right) {
    int den, num;
    den = Fraction::NOK(left.denominator, right.denominator);
    num = left.numerator * den / left.denominator -
          right.numerator * den / right.denominator;
    Fraction result(num, den);
    result.reduction();
    return result;
}

Fraction operator+(const Fraction &left, const Fraction &right) {
    int den, num;
    den = Fraction::NOK(left.denominator, right.denominator);
    num = left.numerator * den / left.denominator +
          right.numerator * den / right.denominator;
    Fraction result(num, den);
    result.reduction();
    return result;
}

Fraction operator*(const Fraction &left, const Fraction &right) {
    Fraction result(left.numerator * right.numerator, left.denominator * right.denominator);
    result.reduction();
    return result;
}

Fraction operator/(const Fraction &left, const Fraction &right) {
    if (right.numerator == 0) throw std::exception();
    Fraction result(left.numerator * right.denominator, left.denominator * right.numerator);
    result.reduction();
    return result;
}

Fraction &Fraction::operator=(const Fraction &right) {
    if (this == &right) {
        return *this;
    }
    this->denominator = right.denominator;
    this->numerator = right.numerator;
    reduction();
    strConstruct();
    return *this;
}

Fraction::operator float() const { return (float) this->numerator / (float) this->denominator; }

ostream &operator<<(ostream &os, const Fraction &one) {
    os << one.str;
    return os;
}

istream &operator>>(istream &is, Fraction &one) {
    char c = ' ';
    is >> one.numerator >> c >> one.denominator;
    one.strConstruct();
    return is;
}

char *Fraction::getStr() { return this->str; }

void Fraction::strConstruct() {
    int num, den, nLen, dLen, i;

    num = numerator;
    den = denominator;
    nLen = countCalc(num);
    dLen = countCalc(den);
    delete[] this->str;
    this->str = new char[nLen + dLen + 2];
    i = 0;
    if (num < 0) {
        num = -num;
        this->str[0] = '-';
        nLen--;
        i++;
    }
    if (den < 0) {
        den = -den;
        this->str[0] = '-';
        dLen--;
        i++;
    }
    std::to_chars(this->str + i, this->str + i + nLen, num);
    i += nLen;
    this->str[i++] = '/';
    std::to_chars(this->str + i, this->str + i + dLen, den);
    i += dLen;
    this->str[i] = '\0';
}

int Fraction::NOD(int a, const int b) {
    int div;
    if (a == b) return a;
    if (a == 0 || b == 0) return 1;
    int d = a - b;
    if (d < 0) {
        d = -d;
        div = NOD(a, d);
    } else
        div = NOD(b, d);
    return div;
}

int Fraction::NOK(const int a, const int b) {
    return a * b / Fraction::NOD(a, b);
}

int Fraction::countCalc(int num) {
    int len;

    len = 0;
    if (num < 0) {
        len++;
        num = -num;
    }
    while (num > 0) {
        len++;
        num = num / 10;
    }
    return len;
}

Fraction::Fraction(Fraction const &b) {
    numerator = b.numerator;
    denominator = b.denominator;
    str = b.str;
}

void Fraction::readFromBinary(istream &is) {
    is.read((char *) &numerator, sizeof(int));
    is.read((char *) &denominator, sizeof(int));
    str = nullptr;
    strConstruct();
}

void Fraction::writeInBinary(ostream &os) {
    os.write((char *) &numerator, sizeof(int));
    os.write((char *) &denominator, sizeof(int));

}
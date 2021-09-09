//
// Created by 777 on 09.09.2021.
//

#include "Fraction.h"
#include <cmath>

Fraction::Fraction() {
    this->numerator = 1;
    this->denominator = 1;
    this->str = nullptr;
}


Fraction::Fraction(int numerator, int denominator) {
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
    Fraction result(left.numerator * right.denominator, left.denominator * right.numerator);
    result.reduction();
    return result;
}

Fraction::operator float() const { return (float) this->numerator / (float) this->denominator; }

char *Fraction::getStr() { return this->str; }

void Fraction::strConstruct() {
    int num, den, nLen, dLen;
    int buf, i;

    num = numerator;
    den = denominator;
    nLen = countCalc(num);
    dLen = countCalc(den);

    this->str = new char[nLen + dLen + 2];
    i = 0;
    if (num < 0) {
        num = -num;
        this->str[0] = '-';
        i++;
    }
    if (den < 0) {
        den = -den;
        this->str[0] = '-';
        i++;
    }
    buf = num;
    for (; buf > 0; ++i) {
        this->str[i] = (char) (buf % 10 + '0');
        buf = buf / 10;
    }
    this->str[i++] = '/';

    buf = den;
    for (; buf > 0; i++) {
        this->str[i] = (char) (buf % 10 + '0');
        buf = buf / 10;
    }
    this->str[i] = '\0';
}

int Fraction::NOD(int a, const int b) {
    int div;
    if (a == b) return a;
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
    while (num > 0) {
        len++;
        num = num / 10;
    }
    return len;
}
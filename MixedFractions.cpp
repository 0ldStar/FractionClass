//
// Created by 777 on 10.09.2021.
//

#include "MixedFractions.h"

#include <charconv>

MixedFractions::MixedFractions() : Fraction() {
    this->integer = 1;
}

void MixedFractions::strConstruct() {
    Fraction::strConstruct();
    char *buf;
    int len, num, i;

    num = integer;
    len = countCalc(num);
    buf = new char[strlen(this->str) + len + 3];
    i = 0;
    if (num < 0) {
        num = -num;
        buf[0] = '-';
        len--;
        i++;
    }

    std::to_chars(buf + i, buf + i + len, num);
    i += len;
    buf[i++] = '|';
    buf[i] = '\0';
    strcat(buf, this->str);
    delete[] this->str;
    this->str = buf;
}

MixedFractions::MixedFractions(int integer, int numerator, int denominator) : Fraction(numerator, denominator),
                                                                              integer(integer) {
    strConstruct();
}

MixedFractions::MixedFractions(MixedFractions &a) : MixedFractions(a.integer, a.numerator, a.denominator) {}

void MixedFractions::reduction() {
    Fraction::reduction();
    integer += numerator / denominator;
    if (numerator < 0) {
        if (numerator / denominator != 0) numerator *= -1;
    }
    numerator -= numerator / denominator * denominator;
}

MixedFractions operator-(const MixedFractions &left, const MixedFractions &right) {

    int den, num;

    den = Fraction::NOK(left.denominator, right.denominator);
    num = (left.numerator + left.integer * left.denominator) * den / left.denominator -
          (right.numerator + right.integer * right.denominator) * den / right.denominator;
    MixedFractions result(0, num, den);
    result.reduction();
    result.strConstruct();
    return result;
}

MixedFractions operator+(const MixedFractions &left, const MixedFractions &right) {
    int den, num;

    den = Fraction::NOK(left.denominator, right.denominator);
    num = (left.numerator + left.integer * left.denominator) * den / left.denominator +
          (right.numerator + right.integer * right.denominator) * den / right.denominator;
    MixedFractions result(0, num, den);
    result.reduction();
    result.strConstruct();
    return result;
}

MixedFractions operator*(const MixedFractions &left, const MixedFractions &right) {
    MixedFractions result(0, (left.numerator + left.integer * left.denominator) *
                             (right.numerator + right.integer * right.denominator),
                          left.denominator * right.denominator);
    result.reduction();
    return result;
}

MixedFractions operator/(const MixedFractions &left, const MixedFractions &right) {
    MixedFractions result(0, (left.numerator + left.integer * left.denominator) * right.denominator,
                          (right.numerator + right.integer * right.denominator) * left.denominator);
    result.reduction();
    return result;
}

MixedFractions &MixedFractions::operator=(const MixedFractions &right) {
    if (this == &right) {
        return *this;
    }
    this->denominator = right.denominator;
    this->numerator = right.numerator;
    this->integer = right.integer;
    reduction();
    strConstruct();
    return *this;
}

MixedFractions::operator float() const {
    return (float) (this->numerator + this->integer * this->denominator) / (float) this->denominator;
}




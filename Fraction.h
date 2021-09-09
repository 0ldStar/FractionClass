//
// Created by 777 on 09.09.2021.
//

#ifndef LABA3_1_5_FRACTION_H
#define LABA3_1_5_FRACTION_H

#include <cstring>

class Fraction {
public:
    Fraction();

    Fraction(Fraction &a);

    Fraction(int numerator, int denominator);

    char *getStr();

    friend Fraction operator+(const Fraction &left, const Fraction &right);

    friend Fraction operator-(const Fraction &left, const Fraction &right);

    friend Fraction operator*(const Fraction &left, const Fraction &right);

    friend Fraction operator/(const Fraction &left, const Fraction &right);

    Fraction &operator=(const Fraction &right) {
        if (this == &right) {
            return *this;
        }
        this->denominator = right.denominator;
        this->numerator = right.numerator;
        reduction();
        strConstruct();
        return *this;
    }
    operator float() const;
    ~Fraction();

private:
    void reduction();

    static int NOD(int a, int b);

    static int NOK(int a, int b);

    void strConstruct();

    static int countCalc(int num);

    int numerator;
    int denominator;
    char *str;
};


#endif //LABA3_1_5_FRACTION_H

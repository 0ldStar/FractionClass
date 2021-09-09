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

    Fraction operator+(const Fraction &other) const {
        Fraction result(0, 0);
        result.denominator = NOK(this->denominator, other.denominator);
        result.numerator = this->numerator * result.denominator / this->denominator +
                           other.numerator * result.denominator / other.denominator;
        result.strConstruct();
        result.reduction();
        return result;
    }

    Fraction operator-(const Fraction &other) const {
        int den, num;
        den = NOK(this->denominator, other.denominator);
        num = this->numerator * den / this->denominator -
              other.numerator * den / other.denominator;
        Fraction result(num, den);
        result.reduction();
        return result;
    }

    Fraction operator*(const Fraction &other) const {
        Fraction result(this->numerator * other.numerator, this->denominator * other.denominator);
        result.reduction();
        return result;
    }

    Fraction operator/(const Fraction &other) const {
        Fraction result(this->numerator * other.denominator, this->denominator * other.numerator);
        result.reduction();
        return result;
    }

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

    ~Fraction() {
        delete[]this->str;
    }

private:
    void reduction();

    static int NOD(const int a, const int b);

    static int NOK(const int a, const int b);

    void strConstruct();

    static int countCalc(int num);

    int numerator;
    int denominator;
    char *str;
};


#endif //LABA3_1_5_FRACTION_H

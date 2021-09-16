//
// Created by 777 on 10.09.2021.
//

#ifndef LABA3_1_5_MIXEDFRACTIONS_H
#define LABA3_1_5_MIXEDFRACTIONS_H

#include "Fraction.h"

class MixedFractions : public Fraction {
public:
    MixedFractions();

    MixedFractions(int integer, int numerator, int denominator);

    MixedFractions(MixedFractions &a);

    void strConstruct();

    void reduction();
    friend MixedFractions operator+(const MixedFractions &left, const MixedFractions &right);

    friend MixedFractions operator-(const MixedFractions &left, const MixedFractions &right);

    friend MixedFractions operator*(const MixedFractions &left, const MixedFractions &right);

    friend MixedFractions operator/(const MixedFractions &left, const MixedFractions &right);
     MixedFractions &operator=(const MixedFractions &right) {
        if (this == &right) {
            return *this;
        }
        this->integer = right.integer;
        this->denominator = right.denominator;
        this->numerator = right.numerator;
        this->reduction();
        this->strConstruct();
        return *this;
    }
    operator float() const;
private:
    int integer;
};


#endif //LABA3_1_5_MIXEDFRACTIONS_H

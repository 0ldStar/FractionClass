//
// Created by 777 on 15.09.2021.
//

#ifndef LABA3_1_5_COMPLETEFREACION_H
#define LABA3_1_5_COMPLETEFREACION_H

#include "Fraction.h"

class CompleteFreacion : public Fraction {
public:
    CompleteFreacion();

    CompleteFreacion(CompleteFreacion &a);

    CompleteFreacion(int numerator, int denominator);
    double getRez();

private:
    double rez;
};


#endif //LABA3_1_5_COMPLETEFREACION_H

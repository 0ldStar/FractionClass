//
// Created by 777 on 15.09.2021.
//

#ifndef LABA3_1_5_COMPLETEFRACION_H
#define LABA3_1_5_COMPLETEFRACION_H

#include "Fraction.h"

class CompleteFracion : public Fraction {
public:
    CompleteFracion();

    CompleteFracion(CompleteFracion &a);

    CompleteFracion(int numerator, int denominator);
    double getRes();

private:
    double rez;
};


#endif //LABA3_1_5_COMPLETEFRACION_H

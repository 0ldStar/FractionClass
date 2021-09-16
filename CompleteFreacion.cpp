//
// Created by 777 on 15.09.2021.
//

#include "CompleteFreacion.h"

CompleteFreacion::CompleteFreacion() : Fraction() {
    this->rez = 1;
}

CompleteFreacion::CompleteFreacion(int numerator, int denominator) : Fraction(numerator, denominator) {
    this->rez = numerator / (double) denominator;
}

CompleteFreacion::CompleteFreacion(CompleteFreacion &a) : CompleteFreacion(a.numerator, a.denominator) {}



double CompleteFreacion::getRez() { return this->rez; }
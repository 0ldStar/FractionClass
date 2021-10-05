//
// Created by 777 on 15.09.2021.
//

#include "CompleteFracion.h"

CompleteFracion::CompleteFracion() : Fraction() {
    this->res = 1;
}

CompleteFracion::CompleteFracion(int numerator, int denominator) : Fraction(numerator, denominator) {
    this->res = numerator / (double) denominator;
}

CompleteFracion::CompleteFracion(CompleteFracion &a) : CompleteFracion(a.numerator, a.denominator) {}



double CompleteFracion::getRes() { return this->res; }
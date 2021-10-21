//
// Created by 777 on 10.10.2021.
//

#ifndef LABA3_1_5_NODE_H
#define LABA3_1_5_NODE_H

#include "Fraction.h"

struct node {
    node *next;
    Fraction &fraction;

    node(Fraction &_fraction) : next(nullptr), fraction(_fraction) {}
};

#endif //LABA3_1_5_NODE_H

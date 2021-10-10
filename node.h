//
// Created by 777 on 10.10.2021.
//

#ifndef LABA3_1_5_NODE_H
#define LABA3_1_5_NODE_H

#include "Fraction.h"

template<typename T>

struct node {
    node *prev;
    node *next;
    T &t;

    node(T &_T) : prev(nullptr), next(nullptr), t(_T) {}
};

#endif //LABA3_1_5_NODE_H

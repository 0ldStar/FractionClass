//
// Created by 777 on 10.10.2021.
//

#ifndef LABA3_1_5_LIST_H
#define LABA3_1_5_LIST_H

#include "node.h"
#include "Fraction.h"
#include <optional>

template<typename T>

class List {
public:
    List();

    bool isEmpty();

    void pushBack(T &_T);

    void pushFront(T &_T);

    T &operator[](int i);

    void popFront();

private:
    node<T> *begin;
    node<T> *end;
};

#endif //LABA3_1_5_LIST_H

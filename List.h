//
// Created by 777 on 10.10.2021.
//

#ifndef LABA3_1_5_LIST_H
#define LABA3_1_5_LIST_H

#include "node.h"
#include "Fraction.h"
#include <optional>

// template
class List {
public:
    List() : begin(nullptr), end(nullptr) {}

    bool isEmpty() { return begin == nullptr; }

    void pushBack(Fraction &_fraction) {
        auto *tmp = new node(_fraction);
        if (isEmpty()) {
            begin = tmp;
            end = tmp;
        } else {
            end->next = tmp;
            end = tmp;
        }
    }

    void pushFront(Fraction &_fraction) {
        auto *tmp = new node(_fraction);
        if (isEmpty()) {
            begin = tmp;
            end = tmp;
        } else {
            tmp->next = begin;
            begin = tmp;
        }

    }

    Fraction &operator[](int i) {
        if (begin == end) throw exception();
        node *tmp = begin;
        for (int j = 0; j < i; ++j) {
            tmp = tmp->next;
            if (tmp == nullptr) throw exception();
        }
        return tmp->fraction;
    }

    void popFront() {
        if (isEmpty()) return;
        node *tmp = begin;
        begin = tmp->next;
        delete tmp;
    }

private:
    node *begin;
    node *end;
};

#endif //LABA3_1_5_LIST_H

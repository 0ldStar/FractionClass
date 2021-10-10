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
    List() : begin(nullptr), end(nullptr) {}

    bool isEmpty() { return begin == nullptr; }

    void pushBack(T &_T) {
        auto *tmp = new node(_T);
        if (isEmpty()) {
            begin = tmp;
            end = tmp;
        } else {
            end->next = tmp;
            end = tmp;
        }
    }

    void pushFront(T &_T) {
        auto *tmp = new node(_T);
        if (isEmpty()) {
            begin = tmp;
            end = tmp;
        } else {
            begin->prev = tmp;
            tmp->next = begin;
            begin = tmp;
        }

    }

    T &operator[](int i) {
        if (begin == end) throw exception();
        node<T> *tmp = begin;
        for (int j = 0; j < i; ++j) {
            tmp = tmp->next;
            if (tmp == nullptr) throw exception();
        }
        return tmp->t;
    }

    void popFront() {
        if (isEmpty()) return;
        node<T> *tmp = begin;
        begin = tmp->next;
        delete tmp;
    }

private:
    node<T> *begin;
    node<T> *end;
};

#endif //LABA3_1_5_LIST_H

#include "List.h"

template<typename T>
List<T>::List() : begin(nullptr), end(nullptr) {}

template<typename T>
bool List<T>::isEmpty() { return begin == nullptr; }

template<typename T>
void List<T>::pushBack(T &_T) {
    auto *tmp = new node(_T);
    if (isEmpty()) {
        begin = tmp;
        end = tmp;
    } else {
        end->next = tmp;
        end = tmp;
    }
}

template<typename T>
void List<T>::pushFront(T &_T) {
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

template<typename T>
T &List<T>::operator[](int i) {
    if (begin == end) throw exception();
    node<T> *tmp = begin;
    for (int j = 0; j < i; ++j) {
        tmp = tmp->next;
        if (tmp == nullptr) throw exception();
    }
    return tmp->t;
}

template<typename T>
void List<T>::popFront() {
    if (isEmpty()) return;
    node<T> *tmp = begin;
    begin = tmp->next;
    delete tmp;
}

template
class List<int>;

template
class List<char>;

template
class List<float>;

template
class List<Fraction>;
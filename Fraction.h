//
// Created by 777 on 09.09.2021.
//

#ifndef LABA3_1_5_FRACTION_H
#define LABA3_1_5_FRACTION_H

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Fraction {
public:
    // Конструктор по умолчанию
    Fraction();

    //Конструктор коппирования
    Fraction(Fraction &a);

    //Конструктор с параметрами
    Fraction(int numerator, int denominator);

    //Метод получения поля строкового представления объекта
    char *getStr();

    //перегруженный оператор сложения
    friend Fraction operator+(const Fraction &left, const Fraction &right);

    //перегруженный оператор вычетания
    friend Fraction operator-(const Fraction &left, const Fraction &right);

    //перегруженный оператор умножения
    friend Fraction operator*(const Fraction &left, const Fraction &right);

    //перегруженный оператор деления
    friend Fraction operator/(const Fraction &left, const Fraction &right);

    //перегруженный оперетор присвоения
    Fraction &operator=(const Fraction &right);

    //операция приведения к типу float
    operator float() const;

    //детсруктор
    ~Fraction();

    //перегруженный оперетор перенаправления вывода в консоль
    friend ostream &operator<<(ostream &os, const Fraction &p);

    //перегруженный оперетор перенаправления ввода из консоли
    friend istream &operator>>(istream &is, Fraction &p);

    //перегруженный оперетор перенаправления вывода в файл
    friend ofstream &operator<<(ofstream &os, Fraction &one);

    //перегруженный оперетор перенаправления ввода из файла
    friend ifstream &operator>>(ifstream &is, Fraction &one);

    /*void binary() {
        ifstream emp_fileOut("../binaryIn.dat");
        emp_fileOut.read((char *) this, sizeof(Fraction));
        this->strConstruct();
        emp_fileOut.close();

    }*/

private:
    //метод сокращения дроби
    void reduction();

    //статичный метод определения НОД
    static int NOD(int a, int b);

    //статичный метод определения НОК
    static int NOK(int a, int b);

    //метод построения строкового представления
    void strConstruct();

    //статичный метод подсчета количества цифр в числе
    static int countCalc(int num);

    int numerator; //поле числителя
    int denominator; //поле знаменателя
    char *str; //поле строкового представления
};


#endif //LABA3_1_5_FRACTION_H

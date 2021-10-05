//#define CATCH_CONFIG_RUNNER

//#include "catch.hpp"
#include <iostream>
#include <cstring>
#include <fstream>
#include "Fraction.h"
#include "CompleteFracion.h"
#include "MixedFractions.h"
#include "gtest/gtest.h"

using namespace std;

int main(int argc, char *argv[]) {
    Fraction a(3, 4);
    cout << a << endl;
    ofstream emp_fileIn("../binaryIn.dat");   // запись в файл структуры
    emp_fileIn.write((char *) &a, sizeof(Fraction));
    emp_fileIn.close();
    Fraction b;
    b.binary();
    cout << "binary " << b << endl;

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


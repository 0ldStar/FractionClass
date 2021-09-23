//#define CATCH_CONFIG_RUNNER

//#include "catch.hpp"
#include <iostream>
#include <cstring>
#include <fstream>
#include "Fraction.h"
#include "CompleteFracion.h"
#include "MixedFractions.h"

using namespace std;

int main() {
    //Catch::Session().run();
    Fraction a(3, 4);
    ofstream fileOut;
    fileOut.open("../write.txt", ofstream::app);
    if (!fileOut.is_open()) {
        std::cerr << "fileOut open failed: " << std::strerror(errno) << "\n";
        return 1;
    }
    fileOut << a << endl;
    fileOut.close();
    ifstream fileIn("../read.txt", ofstream::app);
    if (!fileIn.is_open()) {
        std::cerr << "fileOut open failed: " << std::strerror(errno) << "\n";
        return 1;
    }
    fileIn >> a;
    fileIn.close();
    cout << a << endl;
    ofstream emp_fileIn("../binaryIn.dat");   // запись в файл структуры
    emp_fileIn.write((char *) &a, sizeof(Fraction));
    emp_fileIn.close();
    Fraction b;
    b.binary();
    cout << "binary " << b << endl;
    CompleteFracion d(1, 3);
    cout << d.getRez() << endl;
    MixedFractions f(3, 2, 7);
    MixedFractions e(1, 1, 2);
    cout << f.getStr() << endl;
    cout << e.getStr() << endl;

    f = e / f;
    cout << f.getStr() << endl;
    cout << (float)f << endl;

    return 0;
}


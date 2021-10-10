//#define CATCH_CONFIG_RUNNER

//#include "catch.hpp"
#include <iostream>
#include <cstring>
#include <optional>
#include <fstream>
#include "Fraction.h"
#include "CompleteFracion.h"
#include "MixedFractions.h"
#include "List.h"
#include "gtest/gtest.h"

using namespace std;

int main(int argc, char *argv[]) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


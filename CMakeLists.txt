cmake_minimum_required(VERSION 3.19)
project(laba3_1_5)

set(CMAKE_CXX_STANDARD 14)

add_executable(laba3_1_5 main.cpp Fraction.cpp Fraction.h MixedFractions.cpp MixedFractions.h CompleteFreacion.cpp CompleteFreacion.h)

#find_package(Catch2 3 REQUIRED)
# These tests can use the Catch2-provided main
#target_link_libraries(laba3_1_5 PRIVATE Catch2::Catch2)
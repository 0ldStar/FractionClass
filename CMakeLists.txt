cmake_minimum_required(VERSION 3.19)
project(laba3_1_5)

set(CMAKE_CXX_STANDARD 20)

add_executable(laba3_1_5 main.cpp Fraction.cpp Fraction.h Google_tests/test.cpp)
add_subdirectory(Google_tests)

target_link_libraries(laba3_1_5 gtest gtest_main )

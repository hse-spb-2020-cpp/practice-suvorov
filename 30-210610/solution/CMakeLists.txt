cmake_minimum_required(VERSION 3.10)
project(solution)

set(CMAKE_CXX_STANDARD 17)

add_executable(test_sfinae test_sfinae.cpp doctest_main.cpp)

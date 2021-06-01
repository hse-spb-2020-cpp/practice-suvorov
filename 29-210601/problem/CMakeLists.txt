cmake_minimum_required(VERSION 3.10)
project(solution)

set(CMAKE_CXX_STANDARD 17)

add_executable(test_conditional test_conditional.cpp doctest_main.cpp)
add_executable(test_any test_any.cpp doctest_main.cpp)

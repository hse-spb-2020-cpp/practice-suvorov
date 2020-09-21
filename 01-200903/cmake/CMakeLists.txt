cmake_minimum_required(VERSION 3.10)
project(hello)
set(CMAKE_CXX_STANDARD 17)
add_executable(hello my_hello.cpp)
target_compile_options(hello PUBLIC -Wall -Wextra -Werror)


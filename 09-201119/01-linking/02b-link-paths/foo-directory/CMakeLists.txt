cmake_minimum_required(VERSION 3.10)

project(foo-library)

add_library(foo src/foo.cpp src/foo_internal.cpp)
target_include_directories(foo PUBLIC include)

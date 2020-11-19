cmake_minimum_required(VERSION 3.10)

project(02-include-link-paths)

include_directories(include)
add_executable(main-02 src/main.cpp src/foo.cpp)
#target_include_directories(main-02 include)

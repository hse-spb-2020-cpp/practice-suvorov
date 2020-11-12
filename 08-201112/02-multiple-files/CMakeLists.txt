cmake_minimum_required(VERSION 3.10)

# set the project name
project(02-multiple-files)

# add the executable
add_executable(main main.cpp foo.cpp sum.cpp)

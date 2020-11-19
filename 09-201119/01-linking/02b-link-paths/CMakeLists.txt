cmake_minimum_required(VERSION 3.10)

project(02b-link-paths)

add_subdirectory(foo-directory)

add_executable(main-02 src/main.cpp)
target_link_libraries(main-02 foo)
#target_include_directories(main-02 PUBLIC foo-directory/include)  # Kludges.

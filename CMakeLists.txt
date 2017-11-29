cmake_minimum_required(VERSION 3.7)
project(graphColoring)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp algorithm.h algorithm.cpp graphColoring.h graphColoring.cpp)
add_executable(graphColoring ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.19)
project(TSPquestion)

set(CMAKE_CXX_STANDARD 14)

add_executable(TSPquestion main.cpp TSP.h GA.h life.h life.cpp GA.cpp TSP.cpp)
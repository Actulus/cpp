cmake_minimum_required(VERSION 3.20)
project(parcialis)

set(CMAKE_CXX_STANDARD 14)

add_executable(parcialis main.cpp Item.cpp Item.h Shopping_list.h Shopping_list.cpp)

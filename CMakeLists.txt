cmake_minimum_required(VERSION 3.7)
project(LearnCoding)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BiTree.cpp Grap.cpp Search.cpp MyOrder.cpp MyOrder.h SortFunctions.cpp SortFunctions.h)
add_executable(LearnCoding ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.24)
project(infix_calculator)

set(CMAKE_CXX_STANDARD 20)

add_executable(infix_calculator main.cpp LinkedList.cpp LinkedList.h Stack.cpp Stack.h PostfixCalculator.cpp PostfixCalculator.h)

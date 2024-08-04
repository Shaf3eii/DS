cmake_minimum_required(VERSION 3.27)
project(stack)

set(CMAKE_CXX_STANDARD 20)

add_executable(stack main.cpp
        Stack.h
        Stack.cpp
        Queue.cpp
        Queue.h)

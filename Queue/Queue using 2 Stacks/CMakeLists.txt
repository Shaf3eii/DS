cmake_minimum_required(VERSION 3.27)
project(Queue_using_2_Stacks)

set(CMAKE_CXX_STANDARD 20)

add_executable(Queue_using_2_Stacks main.cpp
        Queue.h
        Queue.cpp
        Stack.cpp
        Stack.h)

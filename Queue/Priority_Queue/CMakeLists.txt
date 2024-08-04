cmake_minimum_required(VERSION 3.27)
project(Priority_Queue)

set(CMAKE_CXX_STANDARD 20)

add_executable(Priority_Queue main.cpp
        Priority_Queue.h
        Priority_Queue.cpp
        Queue.cpp
        Queue.h
        Queue.cpp)

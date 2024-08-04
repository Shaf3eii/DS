cmake_minimum_required(VERSION 3.27)
project(deque)

set(CMAKE_CXX_STANDARD 20)

add_executable(deque
        main.cpp
        Deque.cpp
        Single_List.cpp)

cmake_minimum_required(VERSION 3.31)
project(HW_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(HW_1 main.cpp
        LinkedList.h
        "Circular Doubly Linked List.h"
        Stack.h
        Hash.h
        BST.h)

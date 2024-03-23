cmake_minimum_required(VERSION 3.27)
project(TEST_14 C)

set(CMAKE_C_STANDARD 11)

add_executable(TEST_14 main.c
        libs/data_structures/vector/vector.h
        libs/data_structures/vector/vector.c)

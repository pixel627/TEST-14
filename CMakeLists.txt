cmake_minimum_required(VERSION 3.27)
project(TEST_14 C)

set(CMAKE_C_STANDARD 11)

add_executable(TEST_14 main.c
        libs/data_structures/vector/vector.h
        libs/data_structures/vector/vector.c
        libs/data_structures/matrix/matrix.c
        libs/data_structures/matrix/matrix.h
        libs/data_structures/matrix/matrix_test.c
        libs/data_structures/orderedset/orderedset.c
        libs/data_structures/orderedset/orderedset.h
        libs/data_structures/unorderedset/unorderedset.c
        libs/data_structures/unorderedset/unorderedset.h
        libs/data_structures/vectorvoid/vectorvoid.c
        libs/data_structures/vectorvoid/vectorvoid.h)

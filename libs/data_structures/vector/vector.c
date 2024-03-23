#include "vector.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Создание вектора заданного размера
vector createVector(size_t n) {
    vector v; v.size = n;
    v.capacity = n;
    v.data = (int *)malloc(n * sizeof(int));
    if (v.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return v;
}
#ifndef INC_VECTORVOID_H
#define INC_VECTORVOID_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct vectorVoid {
    void *data;          // указатель на нулевой элемент вектора
    size_t size;         // размер вектора
    size_t capacity;     // вместимость вектора
    size_t baseTypeSize; // размер базового типа
} vectorVoid;

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    vectorVoid v;
    v.data = malloc(n * baseTypeSize);
    v.size = n;
    v.capacity = n;
    v.baseTypeSize = baseTypeSize;
    return v;
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity > v->capacity) {
        v->data = realloc(v->data, newCapacity * v->baseTypeSize);
        v->capacity = newCapacity;
    }
}

void shrinkToFitV(vectorVoid *v) {
    v->data = realloc(v->data, v->size * v->baseTypeSize);
    v->capacity = v->size;
}

void clearV(vectorVoid *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
}

bool isEmptyV(vectorVoid *v) {
    return v->size == 0;
}

bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    char *source = (char *)v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    char *destination = (char *)v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void popBackV(vectorVoid *v) {
    if (v->size > 0) {
        v->size--;
    }
}

void pushBackV(vectorVoid *v, void *source) {
    if (v->size == v->capacity) {
        reserveV(v, v->capacity * 2);
    }
    char *destination = (char *)v->data + v->size * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
    v->size++;
}

#endif // INC_VECTORVOID_H
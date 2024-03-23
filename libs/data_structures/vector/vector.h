#ifndef VECTOR_H #define VECTOR_H

#include <stddef.h> // Для size_t
#include <stdbool.h> // Для типа bool

// Структура вектора
typedef struct {
int *data;	// Указатель на элементы вектора
size_t size;	// Размер вектора
size_t capacity; // Вместимость вектора
} vector;

// Создание вектора заданного размера
vector createVector(size_t n);

// Изменение размера выделенной под вектор памяти
void reserve(vector *v, size_t newCapacity);

// Очистка элементов вектора
void clear(vector *v);

// Освобождение памяти, выделенной под вектор
void shrinkToFit(vector *v);

// Удаление вектора
void deleteVector(vector *v);

// Проверка, является ли вектор пустым
bool isEmpty(vector *v);

// Проверка, является ли вектор полным
bool isFull(vector *v);

// Получение значения элемента вектора по индексу
int getVectorValue(vector *v, size_t i);

// Добавление элемента в конец вектора
void pushBack(vector *v, int x);

#endif
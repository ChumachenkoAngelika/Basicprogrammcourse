#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "vectorVoid.h"

// создание вектора
vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    vectorVoid vecV;
    if (n == 0) {
        vecV.data = NULL;
        vecV.size = 0;
        vecV.capacity = 0;
        vecV.baseTypeSize = baseTypeSize;
        return vecV;
    }
    vecV.data = (int *) malloc(n * sizeof(int));
    if (vecV.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    vecV.size = 0;
    vecV.capacity = n;
    vecV.baseTypeSize = baseTypeSize;
    return vecV;
}

// изменяет количество памяти
void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity > v->capacity) {
        int *newData = (int *) realloc(v->data, newCapacity * v->baseTypeSize);
        if (newData == NULL) {
            fprintf(stderr, "Failed to reallocate memory for the vector\n");
            exit(1);
        }
        v->data = newData;
        v->capacity = newCapacity;
    } else if (newCapacity == 0) {
        v->data = NULL;
    } else if (newCapacity < v->size) {
        v->size = newCapacity;
    }
}

// освобождает память, выделенную под неиспользуемые элементы
void shrinkToFitV(vectorVoid *v) {
    *v->data = (int *) realloc(v->data, v->size * v->baseTypeSize);
    v->capacity = v->size;
}

// удаляет элементы из контейнера, но не освобождает выделенную память
void clearV(vectorVoid *v) {
    v->size = 0;
}

// освобождает память, выделенную вектору
void deleteVectorV(vectorVoid *v) {
    free(v->data);
    v->capacity = 0;
    v->size = 0;
    v->data = NULL;
}


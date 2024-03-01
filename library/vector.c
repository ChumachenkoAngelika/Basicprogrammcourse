#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "vector.h"
#include <stdlib.h>
#include <stdbool.h>

vector createVector(size_t n){
    vector newVector;

    newVector.data = (int*)malloc(n * sizeof(int));
    if (newVector.data == NULL){
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    newVector.size = 0;
    newVector.capacity = n;

    return newVector;
}

void freeVector(vector* vec){
    free(vec->data);
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
}

void reserve(vector *v, size_t newCapacity){
    if(newCapacity == 0){
        free(v->data);
        v->size = 0;
        v->capacity = 0;
    }
}


void clear(vector *v){
    v->size = 0;
}



void shrinkToFit(vector *v) {
    v->data = realloc(v->data, v->size * sizeof(int));
    v->capacity = v->size;
}


void deleteVector(vector *v){
    if (v->data) {
        free(v->data);
    }
    free(v);
}

bool isEmpty(vector *v){
    return v->size == 0;
}


bool isFull(vector *v){
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i){
    return v->data[i];
}


void pushBack(vector *v, int x){
    if (v->size == v->capacity && v->size != 0){
        reserve(v, v->capacity*2);
        v->capacity = v->capacity*2;
    }
    if (v->capacity == 0){
        reserve(v, 1);
        v->capacity = 1;
    }
    v->data[v->size] = x;
    v->size++;
}
//тмовталд

void popBack(vector *v){
    if (v->size ==0){
        fprintf(stderr, "bug!!ERROR!!Warning\n");
        exit(1);
    }else{
        v->size--;
    }
}

int* atVector(vector* v, size_t index) {
    if (index < v->size) {
        return &(v->data[index]);
    } else {
        fprintf(stderr, "IndexError: a[%zu] is not exists\n", index);
        //%zu принимает переменную типа sizet
        return NULL;
    }
}

int* back(vector* v) {
    if (v->size > 0) {
        return &(v->data[v->size - 1]);
    } else {
        return NULL;
    }
}


int* front(vector* v) {
    if (v->size > 0) {
        return &(v->data[0]);
    } else {
        return NULL;
    }
}





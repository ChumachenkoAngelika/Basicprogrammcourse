#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "vector.h"
#include <stdlib.h>

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
}


void deleteVector(vector *v){
    if (v->data) {
        free(v->data);
    }
    free(v);
}
git add .
git commit -m "memory usage of vector"
git push origin master
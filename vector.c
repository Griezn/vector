#include "vector.h"
#include <stdlib.h>

#define cap(X) (2*(X))

void vector_init(Vector *vec){
    vec->size = 0;
    vec->capacity = 2;
    vec->data = malloc(sizeof(int) * vec->capacity);
}

void emplace_back(Vector *vec, int item){
    if (vec->size >= vec->capacity){
        vec->capacity = cap(vec->capacity);
        vec->data = realloc(vec->data, sizeof(int) * vec->capacity);
    }
    vec->data[vec->size++] = item;
}

void reserve(Vector *vec, size_t capacity){
    vec->capacity = capacity;
    vec->data = realloc(vec->data, sizeof(int) * vec->capacity);
}

void shrink_to_fit(Vector *vec){
    vec->capacity = vec->size;
    vec->data = realloc(vec->data, sizeof(int) * vec->capacity);
}

void *back(const Vector *vec){
    return &vec->data[vec->size - 1];
}

void *front(const Vector *vec){
    return &vec->data[0];
}

void *at(const Vector *vec, size_t index){
    if (index < vec->size)
        return &vec->data[index];
    return NULL;
}

void clear(Vector *vec){
    free(vec->data);
    vec->data = malloc(sizeof(int) * vec->capacity);
    vec->size = 0;
}

void pop_back(Vector *vec){
    free(&vec->data[vec->size - 1]) ;
}

void free_vector(Vector *vec){
    free(vec->data);
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
}

#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef struct Vector{
    size_t size;
    size_t capacity;
    int *data;
} Vector;

#define cap(X) (2*(X))

inline __attribute__((always_inline)) void vector_init(Vector *vec){
    vec->size = 0;
    vec->capacity = 2;
    vec->data = malloc(sizeof(int) * vec->capacity);
}

inline __attribute__((always_inline)) void emplace_back(Vector *vec, int item){
    if (vec->size >= vec->capacity){
        vec->capacity = cap(vec->capacity);
        vec->data = realloc(vec->data, sizeof(int) * vec->capacity);
    }
    vec->data[vec->size++] = item;
}

inline __attribute__((always_inline)) void reserve(Vector *vec, size_t capacity){
    vec->capacity = capacity;
    vec->data = realloc(vec->data, sizeof(int) * vec->capacity);
}

inline __attribute__((always_inline)) void shrink_to_fit(Vector *vec){
    vec->capacity = vec->size;
    vec->data = realloc(vec->data, sizeof(int) * vec->capacity);
}

inline __attribute__((always_inline)) void *back(const Vector *vec){
    return &vec->data[vec->size - 1];
}

inline __attribute__((always_inline)) void *front(const Vector *vec){
    return &vec->data[0];
}

inline __attribute__((always_inline)) void *at(const Vector *vec, size_t index){
    if (index < vec->size)
        return &vec->data[index];
    return NULL;
}

inline __attribute__((always_inline)) void clear(Vector *vec){
    free(vec->data);
    vec->data = malloc(sizeof(int) * vec->capacity);
    vec->size = 0;
}

inline __attribute__((always_inline)) void *pop_back(Vector *vec){
    vec->size--;
    return &vec->data[vec->size];
}

inline __attribute__((always_inline)) void free_vector(Vector *vec){
    free(vec->data);
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
}

#endif //VECTOR_H

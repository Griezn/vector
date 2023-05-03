#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector{
    size_t size;
    size_t capacity;
    int *data;
} Vector;

void vector_init(Vector *vec);

void *at(const Vector *vec, size_t index);

void *front(const Vector *vec);

void *back(const Vector *vec);

void reserve(Vector *vec, size_t capacity);

void shrink_to_fit(Vector *vec);

void emplace_back(Vector *vec, int item);

void clear(Vector *vec);

void pop_back(Vector *vec);

void free_vector(Vector *vec);

#endif //VECTOR_H

#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef struct Vector {
    size_t size;
    size_t capacity;
    int *data;
} Vector;


#define cap(X) (2*(X))

/**
 * Initializes a vector
 * @param vec The vector to initialize
 */
inline __attribute__((always_inline)) void vector_init(Vector *vec) {
    vec->size = 0;
    vec->capacity = 2;
    vec->data = malloc(sizeof(int) * vec->capacity);
}

/**
 * Inserts an item at the end of the vector
 * @param vec The vector to insert into
 * @param item The item to insert
 */
inline __attribute__((always_inline)) void emplace_back(Vector *vec, int item) {
    if (vec->size >= vec->capacity) {
        vec->capacity = cap(vec->capacity);
        vec->data = realloc(vec->data, sizeof(int) * vec->capacity);
    }
    vec->data[vec->size++] = item;
}

/**
 * Reserves a certain amount of space for the vector
 * @param vec The vector to reserve space for
 * @param capacity The amount of space to reserve
 */
inline __attribute__((always_inline)) void reserve(Vector *vec, size_t capacity) {
    vec->capacity = capacity;
    vec->data = malloc(sizeof(int) * vec->capacity);
}

/**
 * Resizes the vector to a certain size
 * @param vec The vector to resize
 * @param capacity The size to resize to
 */
inline __attribute__((always_inline)) void resize(Vector *vec, size_t capacity) {
    vec->capacity = capacity;
    vec->data = realloc(vec->data, sizeof(int) * vec->capacity);
}

/**
 * Shrinks the vector to fit the size
 * @param vec The vector to shrink
 */
inline __attribute__((always_inline)) void shrink_to_fit(Vector *vec) {
    vec->capacity = vec->size;
    vec->data = realloc(vec->data, sizeof(int) * vec->capacity);
}

/**
 * Returns the last item in the vector
 * @param vec The vector to get the last item from
 * @return A pointer to the last item in the vector
 */
inline __attribute__((always_inline)) void *back(const Vector *vec) {
    return &vec->data[vec->size - 1];
}

/**
 * Returns the first item in the vector
 * @param vec The vector to get the first item from
 * @return A pointer to the first item in the vector
 */
inline __attribute__((always_inline)) void *front(const Vector *vec) {
    return &vec->data[0];
}

/**
 * Returns the item at a certain index
 * @param vec The vector to get the item from
 * @param index The index to get the item from
 * @return A pointer to the item at the index or NULL if the index is out of bounds
 */
inline __attribute__((always_inline)) void *at(const Vector *vec, size_t index) {
    if (index < vec->size)
        return &vec->data[index];
    return NULL;
}

/**
 * Clears the vector
 * @param vec The vector to clear
 */
inline __attribute__((always_inline)) void clear(Vector *vec) {
    free(vec->data);
    vec->data = malloc(sizeof(int) * vec->capacity);
    vec->size = 0;
}

/**
 * Removes the last item from the vector
 * @param vec The vector to remove the last item from
 * @return The last item in the vector
 */
inline __attribute__((always_inline)) int pop_back(Vector *vec) {
    vec->size--;
    return vec->data[vec->size];
}

/**
 * Frees the vector
 * @param vec The vector to free
 */
inline __attribute__((always_inline)) void free_vector(Vector *vec) {
    free(vec->data);
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
}

/**
 * Appends a range of items to the vector
 * @param vec The vector to append to
 * @param range The range of items to append
 * @param size The size of the range
 */
inline __attribute__((always_inline)) void append_range(Vector *vec, int range[], size_t size) {
    if (vec->capacity - vec->size <= size)
        resize(vec, vec->size + size + 2);

    for (int i = 0; i < size; ++i) {
        emplace_back(vec, range[i]);
    }
}

/**
 * Inserts an item at a certain index
 * @param vec The vector to insert into
 * @param item The item to insert
 * @param index The index to insert at
 */
inline __attribute__((always_inline)) void insert(Vector *vec, int item, size_t index) {
    if (index >= vec->size)
        return;

    if (vec->size >= vec->capacity) {
        vec->capacity = cap(vec->capacity);
        vec->data = realloc(vec->data, sizeof(int) * vec->capacity);
    }

    for (int i = vec->size; i > index; --i) {
        vec->data[i] = vec->data[i - 1];
    }

    vec->data[index] = item;
    vec->size++;
}

#endif //VECTOR_H

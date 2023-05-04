# Vector
Vector is an implementation of a vector data structure written in ANSI C. 
I wrote this project because I needed a fast and dynamic data structure.
And to improve my c coding.

## Usage
This is an example of how you could use the library.

```c
#include "vector.h"

int main(){
    struct Vector vec;
    // initialise the vector
    vector_init(&vec);
    
    // reserve space to make insertion faster
    reserve(&vec, 10);
    
    emplace_back(&vec, 1);
    emplace_back(&vec, 4);
    emplace_back(&vec, 16);
    
    // get an item at an index
    int *res = at(&vec, 1);
    
    // resize the vector so no unnecessary space is occupied
    shrink_to_fit(&vec);
    
    // free the vector
    free_vector(&vec);
    return 0;  
};
```

## Supported functions
````c
// initialise the vector
void vector_init(Vector *vec);

// access an item at an index
void *at(const Vector *vec, size_t index);

// access the first element
void *front(const Vector *vec);

// access the last element
void *back(const Vector *vec);

// reserve space
void reserve(Vector *vec, size_t capacity);

// shrink the vector to the current size
void shrink_to_fit(Vector *vec);

// add an item to the back
void emplace_back(Vector *vec, int item);

// clear the list, capacity is kept
void clear(Vector *vec);

// remove the last element
void pop_back(Vector *vec);

// free the vector
void free_vector(Vector *vec);
````

## Benchmarks
````
Insertions of 5000000 integers

WITHOUT RESERVE
Time taken (averagly)       0.035s
Average time per insert     7ns/op
Inserts per second          142857142

WITH RESERVE 
Time taken (averagly)       0.015s
Average time per insert     3ns/op
Inserts per second          333333333
````
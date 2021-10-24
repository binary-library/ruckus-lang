#ifndef MEMORY_H_
#define MEMORY_H_

#include "common.h"

// macro to multiply capacity by 2
#define GROW_CAPACITY(capacity)                 \
    ((capacity) < 8 ? 8: (capacity) * 2)

// cleans up the call to the reallocate func
// casts the return val of func to the first arg, it returns a pointer
// calculates size of memblock by multiplying count with data size
#define GROW_ARRAY(type, pointer, oldCount, newCount)   \
    (type*)reallocate(pointer, sizeof(type) * (oldCount), \
        sizeof(type) * (newCount))

// cleans call to reallocate, justs calculates size
#define FREE_ARRAY(type, pointer, oldCount)     \
    reallocate(pointer, sizeof(type) * (oldCount), 0)

// wrapper around realloc, returns pointer to new block of mem
void* reallocate(void* pointer, size_t oldSize, size_t newSize);

#endif // MEMORY_H_

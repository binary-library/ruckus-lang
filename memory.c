#include <stdlib.h>
#include "memory.h"

void* reallocate (void* pointer, size_t oldSize, size_t newSize) {
    // entire block must be deleted, free entire mem block
    if (newSize == 0) {
        free(pointer);
        return NULL;
    }

    void* result = realloc(pointer, newSize);
    if (result == NULL) exit(1); // to be handled
    return result;
}

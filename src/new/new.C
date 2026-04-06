#include <stdlib.h>
#include <new.h>

extern void (*_new_handler)();

void* operator new(size_t size) {
    if(size == 0) size = 1;

    void* ptr = malloc(size);

    while (ptr == NULL) {
        if (_new_handler) {
            (*_new_handler)();
        }
        else return 0;
        ptr = malloc(size);
    }

    return ptr;
}

void* operator new(size_t, void* ptr) {
    return ptr;
}

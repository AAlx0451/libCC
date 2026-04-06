#include <stdlib.h>
#include <stddef.h>

typedef void (*__cfront_dtor)(void*, int);

extern "C" {
    void __vec_delete(void* op, int n, int sz, void* f, int del, int) {
        if (!op) return;

        int count = n;
        int has_cookie = 0;

        if (count == -1) {
            int* cookie = (int*)op - 1;
            count = *cookie;
            has_cookie = 1;
        }

        if (f) {
            __cfront_dtor dtor = (__cfront_dtor)f;
            char* ptr = (char*)op + (count * sz);
            int i;
            for (i = 0; i < count; i++) {
                ptr -= sz;
                dtor((void*)ptr, 2);
            }
        }

        if (del) {
            if (has_cookie) {
                free((int*)op - 1);
            } else {
                free(op);
            }
        }
    }
}

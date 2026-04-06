#include <stdlib.h>
#include <stddef.h>

typedef void (*__cfront_ctor)(void*);

extern "C" {
    void* __vec_new(void* op, int n, int sz, void* f) {
        if (op == 0) {
            int* cookie = (int*)malloc(sizeof(int) + (n * sz));
            if (!cookie) return 0;
            *cookie = n;
            op = (void*)(cookie + 1);
        }

        if (f) {
            char* ptr = (char*)op;
            __cfront_ctor ctor = (__cfront_ctor)f;
            int i;
            for (i = 0; i < n; i++) {
                ctor((void*)ptr);
                ptr += sz;
            }
        }

        return op;
    }
}

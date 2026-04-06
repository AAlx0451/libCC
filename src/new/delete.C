#include <stdlib.h>

void operator delete(void* p) {
	if(p != NULL) free(p);
}

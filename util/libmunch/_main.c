#include <stdlib.h>

typedef void (*PFV)();
extern PFV _ctors[];
extern void __dtors();

void _main()
{
    atexit((PFV)__dtors);

    PFV* pf=_ctors;
    for (; *pf; pf++) (**pf)();
}

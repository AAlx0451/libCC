typedef void (*PFV)();
extern PFV _dtors[];

void __dtors() {
    static PFV* current = 0;
    if (current) return;
    PFV* p = _dtors;
    while (*p) p++;
    current = p;
    while (current > _dtors) {
        (*--current)();
    }
}

extern void (*_new_handler)();
void (*_new_handler)() = 0;

void (*set_new_handler(void (*handler)()))()
{
    void (*rr)() = _new_handler;
    _new_handler = handler;
    return rr;
}

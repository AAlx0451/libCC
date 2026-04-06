#ifndef NEW_H
#define	NEW_H

#include <stddef.h>

extern void (*set_new_handler (void(*)()))();

void* operator new(size_t size, void* ptr);

#endif /* !NEW_H */

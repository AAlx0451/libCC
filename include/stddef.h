#ifndef STDDEF_H
#define STDDEF_H

typedef unsigned long size_t;
typedef int ptrdiff_t;

#if !(defined(__cplusplus) && __cplusplus >= 199711L)
typedef short wchar_t;
#endif /* !(__cplusplus && __cplusplus >= 199711L) */

#define NULL ((void*)0)
#define offsetof(type, member) ((size_t)&((type*)0)->member)

#endif /* !STDDEF_H */

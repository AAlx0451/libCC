#ifndef SYS_TYPES_H
#define SYS_TYPES_H

#include <stddef.h>

typedef int pid_t;
typedef unsigned int uid_t;
typedef unsigned int gid_t;

#if defined(__APPLE__)
typedef unsigned short mode_t;
typedef unsigned short nlink_t;
#else
typedef unsigned int mode_t;
typedef unsigned int nlink_t;
#endif /* __APPLE__ */

typedef long time_t;
typedef long ssize_t;
typedef long off_t;
typedef long dev_t;
typedef long ino_t;
typedef unsigned long clock_t;

#endif /* !SYS_TYPES_H */

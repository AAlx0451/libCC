#ifndef UNISTD_H
#define UNISTD_H

#include <stddef.h>
#include <sys/types.h>

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#define F_OK 0
#define X_OK 1
#define W_OK 2
#define R_OK 4

#define _PC_LINK_MAX 1
#define _PC_MAX_CANON 2
#define _PC_MAX_INPUT 3
#define _PC_NAME_MAX 4
#define _PC_PATH_MAX 5
#define _PC_PIPE_BUF 6
#define _PC_CHOWN_RESTRICTED 7
#define _PC_NO_TRUNC 8
#define _PC_VDISABLE 9

#define _SC_ARG_MAX 1
#define _SC_CHILD_MAX 2
#define _SC_CLK_TCK 3
#define _SC_NGROUPS_MAX 4
#define _SC_OPEN_MAX 5
#define _SC_JOB_CONTROL 6
#define _SC_SAVED_IDS 7
#define _SC_VERSION 8

extern char **environ;

extern "C" {
    void _exit(int status);
    
    pid_t fork(void);
    
    ssize_t read(int fd, void *buf, size_t count);
    ssize_t write(int fd, const void *buf, size_t count);
    off_t lseek(int fd, off_t offset, int whence);
    
    int close(int fd);

    int link(const char *oldpath, const char *newpath);
    int unlink(const char *pathname);

    int chdir(const char *path);
    int chown(const char *path, uid_t owner, gid_t group);

    pid_t getpid(void);
    int setuid(uid_t uid);
    uid_t getuid(void);
    uid_t geteuid(void);
    pid_t getppid(void);
    uid_t getegid(void);
    gid_t getgid(void);
    pid_t getpgrp(void);
    int setpgid(pid_t pid, pid_t pgid);
    pid_t setsid(void);
    int setgid(gid_t gid);
    
    int access(const char *pathname, int mode);

    int dup(int oldfd);
    int dup2(int oldfd, int newfd);
    int pipe(int pipefd[2]);

    char *getlogin(void);
    char *getcwd(char *buf, size_t size);
    int getgroups(int gidsetsize, gid_t grouplist[]);

    int rmdir(const char *path);

    int sleep(unsigned int seconds);
    int pause(void);
    unsigned int alarm(unsigned int seconds);

    int execv(const char *path, char *const argv[]);
    int execl(const char *path, const char *arg, ...);
    int execve(const char *pathname, char *const argv[], char *const envp[]);
    int execle(const char *path, const char *arg, ...);
    int execvp(const char *file, char *const argv[]);
    int execlp(const char *file, const char *arg, ...);

    int isatty(int fd);
    pid_t tcgetpgrp(int fd);
    int tcsetpgrp(int fd, pid_t pgrp);
    char *ttyname(int fd);

    long sysconf(int name);
    long pathconf(const char *path, int name);
    long fpathconf(int fd, int name);
}

#endif /* !UNISTD_H */

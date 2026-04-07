#ifndef STDIO_H
#define STDIO_H

#include <stddef.h>
#include <stdarg.h>
#include <sys/types.h>

#define BUFSIZ 1024
#define EOF (-1)

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#define _IOFBF 0
#define _IOLBF 1
#define _IONBF 2

#define L_tmpnam 1024
#define TMP_MAX 10000

#define FOPEN_MAX 20
#define FILENAME_MAX 1024

typedef struct FILE FILE;
typedef off_t fpos_t;

extern FILE *stdin, *stdout, *stderr;
extern FILE *__stdinp, *__stdoutp, *__stderrp;

#if defined(__APPLE__)
#define stdin __stdinp
#define stdout __stdoutp
#define stderr __stderrp
#endif /* __APPLE__ */

extern "C" {
    int fgetc(FILE* f);
    int fputc(int c, FILE* f);
    int getchar(void);
    int putchar(int c);
    int ungetc(int c, FILE* f);
    int putc(int c, FILE* f);
    int getc(FILE* f);
    int fputs(const char* s, FILE* stream);
    int puts(const char* s);
    char* fgets(char* s, int size, FILE* stream);
    int vfprintf(FILE* stream, const char* format, va_list arg);
    int printf(const char* format, ...);
    int fprintf(FILE *stream, const char* format, ...);
    int vprintf(const char *format, va_list ap);
    int sprintf(char *str, const char *format, ...);
    int vsprintf(char *str, const char *format, va_list ap);
    int scanf(const char *format, ...);
    int fscanf(FILE* stream, const char* format, ...);
    int sscanf(const char* str, const char* format, ...);

    FILE* fopen(const char* pathname, const char* mode);
    int fclose(FILE* f);
    FILE* freopen(const char* pathname, const char* mode, FILE* stream);
    size_t fwrite(const void* ptr, size_t size, size_t nmemb, FILE* stream);
    size_t fread(void* ptr, size_t size, size_t nmemb, FILE* stream);

    int fflush(FILE* stream);
    void setbuf(FILE* stream, char* buf);
    int setvbuf(FILE* stream, char* buf, int mode, size_t size);

    int fseek(FILE* stream, long offset, int whence);
    long ftell(FILE* stream);
    void rewind(FILE* stream);

    int fgetpos(FILE* stream, fpos_t* pos);
    int fsetpos(FILE* stream, const fpos_t* pos);

    int rename(const char* oldpath, const char* newpath);
    int remove(const char* pathname);
    FILE* tmpfile(void);
    char* tmpnam(char* s);

    int feof(FILE* p);
    int ferror(FILE* p);
    void clearerr(FILE* p);
    void perror(const char* s);
}

#endif /* !STDIO_H */

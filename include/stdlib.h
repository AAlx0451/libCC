#ifndef STDLIB_H
#define STDLIB_H

#include <stddef.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define RAND_MAX 0x7FFFFFFF
#define MB_CUR_MAX 4

typedef struct {
    int quot;
    int rem;
} div_t;

typedef struct {
    long quot;
    long rem;
} ldiv_t;

extern "C" {
    void free(void *ptr);
    void *malloc(size_t size);
    void *calloc(size_t number, size_t size);
    void *realloc(void *p, size_t size);

    void exit(int status);

    int abs(int num);
    long labs(long num);
    div_t div(int numer, int denom);
    ldiv_t ldiv(long numer, long denom);
    void srand(unsigned int seed);
    int rand(void);

    int atoi(const char *nptr);
    long atol(const char *nptr);
    double atof(const char *str);
    double strtod(const char *str, char **end);
    long strtol(const char* nptr, char** endptr, int base);
    unsigned long strtoul(const char* nptr, char** endptr, int base);

    void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
    void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
    char *getenv(const char *name);
    void abort(void);
    int atexit(void (*func)(void));
    int system(const char *command);

    int mblen(const char *s, size_t n);
    size_t mbstowcs(wchar_t *pwcs, const char *s, size_t n);
    int mbtowc(wchar_t *pwc, const char *s, size_t n);
    size_t wcstombs(char *s, const wchar_t *pwcs, size_t n);
    int wctomb(char *s, wchar_t wchar);
}

#endif /* !STDLIB_H */

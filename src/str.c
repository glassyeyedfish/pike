#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "str.h"

typedef struct {
    size_t len;
} str_header_t;

#define STRING(h) ((char *) (h) + sizeof(str_header_t))
#define HEADER(s) ((str_header_t *) (s) - 1)

static char *
str_realloc(char *s, size_t l)
{
    str_header_t *h = HEADER(s);
    h = realloc(h, sizeof(str_header_t) + l);
    h->len = l;
    char *r = STRING(h);
    return r;
}

char *
str_alloc(const char *c) 
{
    size_t l = strlen(c) + 1;
    str_header_t *h = malloc(sizeof(str_header_t) + l);

    h->len = l;

    char *s = STRING(h);
    strcpy(s, c);

    return s;
}

char *
str_allocc(char c) 
{
    size_t l = 2;
    str_header_t *h = malloc(sizeof(str_header_t) + l);

    h->len = l;

    char *s = STRING(h);
    s[0] = c;
    s[1] = '\0';

    return s;
}

void 
str_free(char *s) 
{
    str_header_t* h = HEADER(s);
    free(h);
}

char *
str_cat(char *s, const char *c)
{
    size_t l = HEADER(s)->len + strlen(c);
    char *r = str_realloc(s, l);
    strcat(r, c);
    HEADER(r)->len = l;
    return r;
}

char *
str_catc(char *s, char c)
{
    size_t l = HEADER(s)->len + 1;
    char *r = str_realloc(s, l);
    r[l] = c;
    r[l+1] = '\0';
    HEADER(r)->len = l;
    return r;
}
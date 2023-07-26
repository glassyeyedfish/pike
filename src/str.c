#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "str.h"

str_t *
str_alloc(const char *c) 
{
    str_t *s = malloc(sizeof(str_t));
    size_t len = strlen(c) + 1;

    s->len = len;
    s->cap = len;
    s->chars = malloc(len);

    strcpy(s->chars, c);
    return s;
}

void 
str_free(str_t *s) 
{
    free(s->chars);
    free(s);
}

void
str_append(str_t *s, const char *c)
{
    
}
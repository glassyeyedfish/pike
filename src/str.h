#ifndef STR_H
#define STR_H

typedef struct {
    size_t len;
    size_t cap;
    char *chars;
} str_t;

str_t *str_alloc(const char *c);
void str_free(str_t *s);

#endif 
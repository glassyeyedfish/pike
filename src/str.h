#ifndef STR_H
#define STR_H

char *str_alloc(const char *c);
char *str_allocc(char c);
void str_free(char *s);
char *str_cat(char *s, const char *c);
char *str_catc(char *s, char c);

#endif 
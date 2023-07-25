#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>

typedef enum {
    TOKEN_PRINTLN,
    TOKEN_LEFT_PAREN,
    TOKEN_RIGHT_PAREN,
    TOKEN_STR
} token_type_t;

typedef struct {
    token_type_t type;
    char *text;
} token_t;

typedef struct {
    int size;
    int cap;
    token_t *tokens;
} token_vec_t;

token_vec_t* token_vec_alloc();
void token_vec_free(token_vec_t* v);
void token_vec_println(token_vec_t* v);

int tokenize(token_vec_t* tokens, FILE* source_code);

#endif
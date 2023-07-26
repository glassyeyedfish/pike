#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>

#include "str.h"

typedef enum {
    TOKEN_PRINTLN,
    TOKEN_LEFT_PAREN,
    TOKEN_RIGHT_PAREN,
    TOKEN_STR
} token_type_t;

/*
 * .id_index = -1 if there is no id
 */
typedef struct {
    token_type_t type;
    str_t *text;
} token_t;

typedef struct {
    int size;
    int cap;
    token_t *tokens;
} token_vec_t;

token_vec_t *token_vec_alloc();
void token_vec_free(token_vec_t *v);
void token_vec_println(token_vec_t *v);
void token_vec_append(token_vec_t *v, token_t t);

int tokenize(token_vec_t *tokens, FILE *source_code);

#endif
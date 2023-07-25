#include <stdio.h>
#include <stdlib.h>

#include "lexer.h"

#define TOKEN_VEC_MAX_CAP 128

token_vec_t* 
token_vec_alloc()
{
    token_vec_t* v = malloc(sizeof(token_vec_t));

    v->size = 0;
    v->cap = TOKEN_VEC_MAX_CAP;
    v->tokens = malloc(TOKEN_VEC_MAX_CAP * sizeof(token_t));

    return v;
}

void 
token_vec_println(token_vec_t* v)
{
    printf("[]\n");
}

void 
token_vec_free(token_vec_t* v)
{
    free(v->tokens);
    free(v);
}
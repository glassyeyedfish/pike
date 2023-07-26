#include <stdio.h>
#include <stdlib.h>

#include "lexer.h"

#define TOKEN_VEC_MAX_CAP 128

token_vec_t * 
token_vec_alloc()
{
    token_vec_t *v = malloc(sizeof(token_vec_t));

    v->size = 0;
    v->cap = TOKEN_VEC_MAX_CAP;
    v->tokens = malloc(TOKEN_VEC_MAX_CAP * sizeof(token_t));

    return v;
}

void 
token_vec_free(token_vec_t* v)
{
    free(v->tokens);
    free(v);
}

void 
token_vec_println(token_vec_t* v)
{
    printf("[");

    if (v->size > 0) {
        // token_print(v->tokens[0]);

        for (int i = 1; i < v->size; i++) {
            printf(", ");
            // token_print(v->tokens[i]);
        }
    }
    printf("]\n");
}

void 
token_vec_append(token_vec_t* v, token_t t) {
    if (v->size == v->cap) {
        v->tokens = realloc(v->tokens, 2 * v->cap);
        v->cap = 2 * v->cap;
    }
    v->size += 1;
    v->tokens[v->size] = t;
}
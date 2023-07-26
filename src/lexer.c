#include <stdio.h>
#include <stdlib.h>

#include "lexer.h"
#include "util.h"

#define TOKEN_VEC_MAX_CAP 128
#define TOKEN_MAX_SIZE 128

static void 
token_print(token_t t)
{
    printf("\"%s\"", t.text);
}

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
        token_print(v->tokens[0]);

        for (int i = 1; i < v->size; i++) {
            printf(", ");
            token_print(v->tokens[i]);
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
    v->tokens[v->size] = t;
    v->size += 1;
}

int
match_sym(token_vec_t *tokens, char c) 
{
    if (c == '(') {
        token_vec_append(tokens, (token_t) {
            .type = TOKEN_LEFT_PAREN,
            .text = str_allocc(c)
        });
    } else if (c == ')') {
        token_vec_append(tokens, (token_t) {
            .type = TOKEN_RIGHT_PAREN,
            .text = str_allocc(c)
        });
    }

    return 0;
}

int 
tokenize(token_vec_t *tokens, FILE *source_code)
{
    char c;
    int flag = 0;

    while (!feof(source_code)) {
        c = fgetc(source_code);

        if (c == '(' || c == ')') flag = match_sym(tokens, c);

        if (flag < 0) return -1;
    }

    return 0;
}
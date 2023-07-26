#include <stdio.h>
#include <string.h>

#include "lexer.h"
#include "str.h"
#include "util.h"

int 
main() 
{
    // FILE *source_code = fopen("examples/test.pk", "r");
    // token_vec_t* tokens = token_vec_alloc();

    // if (source_code == NULL) {
    //     die("fopen:");
    // }

    // token_vec_println(tokens);
    // token_vec_append(tokens);
    // token_vec_println(tokens);

    // token_vec_free(tokens);
    // fclose(source_code);

    str_t *str = str_alloc("Hello!");
    puts(str->chars);
    str_free(str);

    return 0;
}
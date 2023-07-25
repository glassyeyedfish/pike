#include <stdio.h>

#include "lexer.h"
#include "util.h"

int 
main() 
{
    FILE *source_code = fopen("examples/test.pk", "r");
    token_vec_t* tokens = token_vec_alloc();

    if (source_code == NULL) {
        die("fopen:");
    }

    token_vec_println(tokens);

    token_vec_free(tokens);
    fclose(source_code);

    return 0;
}
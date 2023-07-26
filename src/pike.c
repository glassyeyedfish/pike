#include <stdio.h>
#include <string.h>

#include "lexer.h"
#include "str.h"
#include "util.h"

int 
main() 
{
    /* Get a pointer to the source code. */
    FILE *source_code = fopen("examples/test.pk", "r");
    if (source_code == NULL) {
        util_die("fopen:");
    }

    /* Convert source code into tokens. */
    token_vec_t* tokens = token_vec_alloc();
    if (tokenize(tokens, source_code) < 0) {
        util_die("tokenize:");
    }
    token_vec_println(tokens);

    /* Clean up and exit. */
    token_vec_free(tokens);
    fclose(source_code);

    return 0;
}
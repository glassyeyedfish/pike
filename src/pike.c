#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "encode.h"

void 
print_usage(char* prog_name)
{
    printf("Usage: %s [COMMAND] [ARGS...]\n", prog_name);
    printf("\n");
    printf("Commands:\n");
    printf("  e   Encode.\n");
    printf("  d   Decode.\n");
    printf("  r   Run.\n");
}

int
main(int argc, char* argv[])
{
    if (argc < 2) {
        print_usage(argv[0]);
        return 0;
    }

    if (strcmp(argv[1], "e") == 0 && argc == 4) {
        encode(argv[2], argv[3]);
    } else if (strcmp(argv[1], "d") == 0) {
        puts("d");
    } else if (strcmp(argv[1], "r") == 0) {
        puts("r");
    } else {
        print_usage(argv[0]);
        return 0;
    }

    return 0;
}

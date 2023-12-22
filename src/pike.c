#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void 
print_usage(char* prog_name)
{
    printf("Usage: %s\n", prog_name);
}

int
main(int argc, char* argv[])
{
    FILE* f = fopen("test.txt", "r");

    // return 0;

    // fputc('c', f);
    printf("Behold: %c\n", fgetc(f));

    fclose(f);
    return 0;
}

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"

void
die(const char* msg)
{
    fprintf(stderr, "[DIE] %s: %s\n", msg, strerror(errno));
    exit(1);
}
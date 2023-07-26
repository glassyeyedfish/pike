#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"

static int had_custom_error = 0;
static char errmsg[80];

void 
util_seterr(const char *msg)
{
	had_custom_error = 1;
	strncpy(errmsg, msg, 79);
}

void 
util_reseterr()
{
	had_custom_error = 0;
}

void
util_die(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);

	if (fmt[0] && fmt[strlen(fmt)-1] == ':') {
		fputc(' ', stderr);
		if (had_custom_error) {
			fputs(errmsg, stderr);
			fputc('\n', stderr);
		} else {
			perror(NULL);
		}
	} else {
		fputc('\n', stderr);
	}

	exit(EXIT_FAILURE);
}
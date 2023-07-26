#ifndef UTIL_H
#define UTIL_H

void util_seterr(const char *msg);
void util_clearerr();
void util_die(const char *fmt, ...);

#endif
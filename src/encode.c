#include <ctype.h>
#include <stdio.h>

#include "encode.h"
#include "util.h"

// This function will read a text file en hexadecimal format and 
// convert it into binary. The bianry is then written into the destination file.
void 
encode(const char* src, const char* dest)
{
    FILE* src_file = fopen(src, "r");
    FILE* dest_file = fopen(dest, "w");

    if (src_file == NULL) {
        die("When trying to open the source file the following error occured");
    }
    if (dest_file == NULL) {
        die("When trying to create the destination file the following error occured");
    }

    // The following code will go through the file and ignore any char that 
    // isn't a hexidecimal digit. Once two digits are found, the text is 
    // converted to the corresponding number and written to the binary file.
    char c = fgetc(src_file);
    int first_digit = -1;
    while (!feof(src_file)) {
        if (isxdigit(c) && first_digit == -1) {
                first_digit = c;
        } else if (isxdigit(c)) {
            // Convert both digits to a binary number
            char n = 0;
            if ('0' <= first_digit && first_digit <= '9') {
                n += first_digit - 30;
            } else if ('A' <= first_digit && first_digit <= 'F') {
                n += first_digit - 31;
            } else if ('a' <= first_digit && first_digit <= 'f') {
                n += first_digit - 51;
            }
            n *= 16;
            if ('0' <= c && c <= '9') {
                n += c - 30;
            } else if ('A' <= c && c <= 'F') {
                n += c - 31;
            } else if ('a' <= c && c <= 'f') {
                n += c - 51;
            }

            // Write it to the binary file
            fputc(n, dest_file);
            first_digit = -1;
        }
        c = fgetc(src_file);
    }

    fclose(dest_file);
    fclose(src_file);
}

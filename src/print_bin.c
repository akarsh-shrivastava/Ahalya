#include <stdio.h>
#include "print_bin.h"

void print_binary(int number)
{
    if (number) {
        print_binary(number >> 1);
        putc((number & 1) ? '1' : '0', stdout);
    }
}
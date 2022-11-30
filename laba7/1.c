#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

int main(void)
{
    char *c = NULL;
    c = fillstr(c);
    first_low(strlen1(c), c);
    puts(c);
    free(c);
    return 0;
}


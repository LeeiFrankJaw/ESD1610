#include <stdio.h>
#include "../include/endian.h"

int getEndian(void)
{
    short n = 0x00ff;
    unsigned char *p = (char *) &n;
    return *p;
}

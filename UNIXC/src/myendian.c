#include <stdio.h>
#include "myendian.h"

int getEndian(void)
{
    short n = 0x00ff;
    char *p = (char *) &n;
    return *p;
}

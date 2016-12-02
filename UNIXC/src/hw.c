#include <stdio.h>
#include "hw.h"

int getEndian(void)
{
    short n = 0x00ff;
    char *p = (char *) &n;
    return *p;
}

char *myStrcpy(char *dest, const char *src)
{
    while (*dest++ = *src++);
}

int myStrlen(const char *s)
{
    int i;
    for (i = 0; *s != '\0'; s++,i++)
	;
    return i;
}

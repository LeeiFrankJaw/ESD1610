#include "mystr.h"

char *myStrcpy(char *dest, const char *src)
{
    while ((*dest++ = *src++));
    return dest;
}

int myStrlen(const char *s)
{
    int i;
    for (i = 0; *s != '\0'; s++,i++)
	;
    return i;
}

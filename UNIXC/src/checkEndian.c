#include <stdio.h>
#include "../include/endian.h"

int main()
{
    if (getEndian())
	printf("This is a little endian machine, :)\n");
    else
	printf("This is a big endian machine, :<\n");
}

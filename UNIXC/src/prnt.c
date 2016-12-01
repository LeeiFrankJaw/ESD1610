#include <stdio.h>
#include "prnt.h"

int printDiamond(int n)
{
    if (n%2 == 0) {
	printf("Please input an odd integer!");
	return 1;
    }

    int i, j, h = n/2;

    for (i = 0; i < n; i++) {
    	int l = (i < h) ? (h + i) : (n - 1 + h - i);
    	int b = (i < h) ? (h - i) : (i - h);
    	for (j = 0; j <= l; j++)
    	    printf(j < b ? " " : "*");
    	printf("\n");
    }

    return 0;
}

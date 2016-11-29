#include <stdlib.h>
#include "../include/prnt.h"

int main(int argc, char *argv[])
{
    int n = (argc > 1) ? atoi(argv[1]) : 5;
    printDiamond(n);
}

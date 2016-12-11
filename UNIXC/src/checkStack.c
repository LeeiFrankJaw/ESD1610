#include "hw_hdr.h"
#include "mystack.h"

int main(int argc, char *argv[])
{
    if (argc <=1 )
    	return 0;

    initStack();

    int i, n = 0;
    for (i = 1; i < argc; i++)
    	if (!strcmp(argv[i], "clear")) {
    	    clear();
    	    n = 0;
    	} else {
    	    push(atoi(argv[i]));
    	    n++;
    	}
    for (i = 1; i <= n; i++)
    	pop();
}

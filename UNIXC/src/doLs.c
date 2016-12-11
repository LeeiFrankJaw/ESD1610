#include "hw_hdr.h"
#include "myls.h"

int main(int argc, char *argv[])
{
    if (argc <= 1) {
	puts("Usage: myls filename");
	exit(EXIT_SUCCESS);
    }

    char errStr[MAX_ESTR];
    struct stat sb;

    if (lstat(argv[1], &sb) == -1) {
	sprintf(errStr, "myls: cannot access '%s'", argv[1]);
	perror(errStr);
	exit(EXIT_FAILURE);
    }

    char outStr[MAX_OSTR];
    char modeStr[11] = "----------";

    setModeStr(sb.st_mode, modeStr);

    sprintf(outStr, "%s %ld %ld %s",
	    modeStr,
	    (long) sb.st_nlink,
	    (long) sb.st_size,
	    argv[1]);
    puts(outStr);

    return 0;
}

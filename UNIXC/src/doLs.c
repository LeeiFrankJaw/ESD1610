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

    char modeStr[] = "----------";
    char timeStr[MAX_TSTR];

    printf("%s %ld %s %s %ld %s %s\n",
	   getModeStr(sb.st_mode, modeStr),
	   (long) sb.st_nlink,
	   getpwuid(sb.st_uid)->pw_name,
	   getgrgid(sb.st_gid)->gr_name,
	   (long) sb.st_size,
	   getTimeStr(sb.st_mtime, timeStr),
	   argv[1]);

    return 0;
}

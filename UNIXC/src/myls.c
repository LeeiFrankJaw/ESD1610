#include "hw_hdr.h"
#include "myls.h"

static inline char *getFileType(mode_t, char []) INLINE;
static inline char *getFilePerms(mode_t, char []) INLINE;

static inline char *getFileType(mode_t st_mode, char modeStr[])
{
    switch (st_mode & S_IFMT) {
	case S_IFREG:
	    modeStr[0] = '-';
	    break;
	case S_IFBLK:
	    modeStr[0] = 'b';
	    break;
	case S_IFCHR:
	    modeStr[0] = 'c';
	    break;
	case S_IFDIR:
	    modeStr[0] = 'd';
	    break;
	case S_IFLNK:
	    modeStr[0] = 'l';
	    break;
	case S_IFIFO:
	    modeStr[0] = 'p';
	    break;
	case S_IFSOCK:
	    modeStr[0] = 's';
	    break;
	default:
	    modeStr[0] = '?';
	    break;
    }
    return modeStr;
}

static inline char *getFilePerms(mode_t st_mode, char modeStr[])
{
    int i;
    for (i = 0; i < 9; i++)
	if (st_mode >> i & 1) {
	    switch (i % 3) {
		case 0:
		    modeStr[9-i] = 'x';
		    break;
		case 1:
		    modeStr[9-i] = 'w';
		    break;
		case 2:
		    modeStr[9-i] = 'r';
		    break;
	    }
	}
    return modeStr;
}

char *getModeStr(mode_t st_mode, char modeStr[])
{
    return getFilePerms(st_mode, getFileType(st_mode, modeStr));
}

char *getTimeStr(time_t st_time, char timeStr[])
{
    strftime(timeStr, MAX_TSTR, "%b %d %R", localtime(&st_time));
    return timeStr;
}

#ifndef MYLS_H
#define MYLS_H

#include <sys/stat.h>
#include <limits.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define MAX_ESTR (UCHAR_MAX * 2)
#define MAX_TSTR (30)

#ifdef __GNUC__
#define INLINE __attribute__((__always_inline__))
#else
#define INLINE
#endif

char *getModeStr(mode_t, char []);
char *getTimeStr(time_t, char []);

#endif

#ifndef MYLS_H
#define MYLS_H

#include <sys/stat.h>
#include <limits.h>

#define MAX_ESTR (UCHAR_MAX * 2)
#define MAX_OSTR (UCHAR_MAX * 3)

#ifdef __GNUC__
#define INLINE __attribute__((__always_inline__))
#else
#define INLINE
#endif

char *setModeStr(mode_t, char []);

#endif

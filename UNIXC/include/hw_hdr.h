#ifndef HW_HDR_H
#define HW_HDR_H

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define min(m, n) ((m) < (n) ? (m) : (n))
#define max(m, n) ((m) < (n) ? (n) : (m))

typedef enum {FALSE, TRUE} Bool;

#endif

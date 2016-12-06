#ifndef HW_H
#define HW_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define min(m, n) ((m) < (n) ? (m) : (n))
#define max(m, n) ((m) < (n) ? (n) : (m))

typedef enum {FALSE, TRUE} Bool;

int getEndian(void);
char *myStrcpy(char *dest, const char *src);
int myStrlen(const char *s);
void initStack(void);
void checkStackInit(void);
void push(int);
int pop(void);
void clear(void);

#endif

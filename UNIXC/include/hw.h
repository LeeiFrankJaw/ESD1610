#ifndef hw_h
#define hw_h
int getEndian(void);
char *myStrcpy(char *dest, const char *src);
int myStrlen(const char *s);
void initStack(void);
void checkStackInit(void);
void push(int);
int pop(void);
void clear(void);
#endif

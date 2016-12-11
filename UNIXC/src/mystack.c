#include "hw_hdr.h"
#include "mystack.h"

int *stack = NULL;

void initStack(void)
{
    printf("%c", '\0');
    stack = sbrk(0);
    if (!stack) {
	printf("Error: failed initializing the stack\n");
	exit(EXIT_FAILURE);
    }
    printf("stack initialized at %p\n", stack);
}

void checkStackInit(void)
{
    if (!stack) {
	printf("Error: the stack is not initialized.\n");
	exit(EXIT_FAILURE);
    }
}

void push(int data)
{
    checkStackInit();
    int *sp = sbrk(sizeof(int));
    if (!sp) {
	printf("Error: failed allocating space for the stack\n");
	exit(EXIT_FAILURE);
    }
    printf("push data %d at %p\n", *sp = data, sp);
}

int pop(void)
{
    checkStackInit();
    int *sp = sbrk(0);
    if (sp <= stack) {
	printf("Error: the stack is empty.\n");
	exit(EXIT_FAILURE);
    }
    
    int data = *--sp;
    printf("pop out %d at %p\n", *sp, sp);
    sbrk(-sizeof(int));
    return data;
}

void clear(void)
{
    checkStackInit();
    int failed = brk(stack);
    if (failed) {
	printf("Error: failed clearing the stack.\n");
	exit(EXIT_FAILURE);
    }
}

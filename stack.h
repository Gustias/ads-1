#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stddef.h>

typedef int mydata;

typedef struct Stack Stack;

Stack* createStack(void);
int    push(Stack *stack, mydata data);
int    pop(Stack *stack, mydata *data);
bool   isEmpty(Stack *stack);
bool   isFull(Stack *stack);
void   destroyStack(Stack **stack);

#endif
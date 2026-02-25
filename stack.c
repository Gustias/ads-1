#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

// Errors
#define STACK_NOT_CREATED 0
#define ALLOCATION_FAIL 1
#define OUT_OF_MEMORY 2
#define EMPTY_STACK 3

static const char *errmsg[] = {
    "Stack is not created.",
    "Unable to allocate memory.",
    "Unable to push (out of memory).",
    "Unable to pop, stack is empty."
};

// Stack structure
struct Stack {
    mydata *data;
    size_t size;
    size_t capacity;
    bool created;
};

// All functions
static int ensure_capacity(Stack *stack, size_t need)
{
    if (stack->capacity >= need) return 0;

    size_t new_cap = (stack->capacity == 0) ? 4 : stack->capacity * 2;
    while (new_cap < need) new_cap *= 2;

    mydata *new_data = (mydata*)realloc(stack->data, new_cap * sizeof(mydata));
    if (!new_data) return 1;

    stack->data = new_data;
    stack->capacity = new_cap;
    return 0;
}

Stack* createStack(void)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        fprintf(stderr, "Error: %s\n", errmsg[ALLOCATION_FAIL]);
        return NULL;
    }

    stack->size = 0;
    stack->capacity = 4; /* pradine talpa */
    stack->data = (mydata*)malloc(stack->capacity * sizeof(mydata));
    if (!stack->data) {
        fprintf(stderr, "Error: %s\n", errmsg[ALLOCATION_FAIL]);
        free(stack);
        return NULL;
    }

    stack->created = true;
    return stack;
}

int push(Stack *stack, mydata data)
{
    if (stack == NULL || !stack->created) {
        fprintf(stderr, "Error: %s\n", errmsg[STACK_NOT_CREATED]);
        return 1;
    }

    if (ensure_capacity(stack, stack->size + 1) != 0) {
        fprintf(stderr, "Error: %s\n", errmsg[OUT_OF_MEMORY]);
        return 1;
    }

    stack->data[stack->size++] = data;
    return 0;
}

int pop(Stack *stack, mydata *data)
{
    if (stack == NULL || !stack->created) {
        fprintf(stderr, "Error: %s\n", errmsg[STACK_NOT_CREATED]);
        return 1;
    }

    if (stack->size == 0) {
        fprintf(stderr, "Error: %s\n", errmsg[EMPTY_STACK]);
        return 1;
    }

    stack->size--;
    if (data) *data = stack->data[stack->size];
    return 0;
}

bool isEmpty(Stack *stack)
{
    if (stack == NULL || !stack->created) {
        fprintf(stderr, "Error: %s\n", errmsg[STACK_NOT_CREATED]);
        return false;
    }
    return stack->size == 0;
}

bool isFull(Stack *stack)
{
    if (stack == NULL || !stack->created) {
        fprintf(stderr, "Error: %s\n", errmsg[STACK_NOT_CREATED]);
        return false;
    }
    return stack->size == stack->capacity;
}

void destroyStack(Stack **stack)
{
    if (stack == NULL || *stack == NULL || !(*stack)->created) {
        fprintf(stderr, "Error: %s\n", errmsg[STACK_NOT_CREATED]);
        return;
    }

    free((*stack)->data);
    (*stack)->data = NULL;
    (*stack)->size = 0;
    (*stack)->capacity = 0;
    (*stack)->created = false;

    free(*stack);
    *stack = NULL;
}
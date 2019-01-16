#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

#define STACK_SIZE 100

// using fixed length array
struct stack_type {
    int contents[STACK_SIZE];
    int top;
};

Stack create(void){
    Stack s = malloc(sizeof(struct stack_type));
    if(s == NULL)
        exit(EXIT_FAILURE);
    s->top = 0;
    return s;
}

void destroy(Stack s){
    free(s);
}

void make_empty(Stack s){
    s-> top = 0;
}

bool is_empty(Stack s){
    return s->top == 0;
}

bool is_full(Stack s){
    return s->top == STACK_SIZE;
}

void push(Stack s, int n){
    if(is_full(s))
        exit(EXIT_FAILURE);
    s->contents[s->top++] = n;
}

int pop(Stack s){

    if(is_empty(s))
        exit(EXIT_FAILURE);
    return s->contents[--s->top];
}

/* Using global variable to implement a stack */
#include <stdbool.h>

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int top = 0;

void make_empty() {
    top = 0;
}

bool is_empty() {
    return top == 0;
}

bool is_full() {
    return top == STACK_SIZE;
}

void push(int i) {
    if(is_full()) return;
    else
        contents[top++] = i;
}

int pop(){
    if(is_empty()){
        return -1;
    } else {
        return contents[--top];
    }
}

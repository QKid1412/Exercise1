#include <stdio.h>
#include <stdlib.h>
#inclue "stack.h"

struct node{
    int data;
    struct node *next;
};

static struct node *top = NULL;

void make_empty(){
    while(!is_empty())
        pop();
}

bool is_empty(){
    return top == NULL;
}

void push(int i){
    struct node *new_node = malloc(sizeof(struct node));
    if(new_node == NULL)
        return;

    new_node->data = i;
    new_node->next = top;
    top = new_node;
}

int pop(){
    struct node *old_node;
    int i;

    if(is_empty())
        return;

    old_node = top;
    i = top->data;
    top = top->next;
    free(old_node);
    return i;
}

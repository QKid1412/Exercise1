#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
}node;


// rotate double linked list counter-clockwise
node *update(node*start, int p)
{
    //Add your code here
    if(start == NULL || p == 0){
        return start;
    }

    int count = 0;
    node *extend_start = start;
    node *new_tail;
    node *new_head = start;

    while(count < p && new_head != NULL && new_head->next != NULL){
        new_tail = new_head;
        new_head = new_head->next;
        count++;
    }

    new_head->prev = NULL;
    node *temp = new_head;
    while(temp != NULL && temp->next != NULL){
        temp = temp->next;
    }
    temp->next = extend_start;
    new_tail->next = NULL;

    return new_head;

}

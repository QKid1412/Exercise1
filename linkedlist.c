// A simple C program to introduce
// a linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  int data;
  struct Node *next;
} Node;

 // insert at head
void push(Node **head, int val){
    Node *new_node = (Node *)malloc(sizeof(Node*));
    new_node -> data = val;
    new_node -> next = *head;
    *head = new_node;
}

void append(Node **head, int val){
    Node *new_node = (Node *)malloc(sizeof(Node*));
    new_node -> data = val;
    new_node -> next = NULL;
    Node *curr = *head;

    if(*head == NULL){
        *head = new_node;
        return;
    }

    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = new_node;
    return;
}

void insertAfter(Node *prev, int val){
    if(prev == NULL){ return; }

    Node *new_node = (Node *)malloc(sizeof(Node*));
    new_node -> data = val;
    new_node -> next = prev -> next;

    prev -> next = new_node;
    return;
}

 void printList(Node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
}

void deleteNode(Node **head, int val){
    Node *curr = *head;
    Node *prev = *head;
    if( curr == NULL ){ return; }

    if( curr->data == val){
        *head = curr->next;
        free(curr);
        return;
    }

    while( curr->next != NULL && curr->data != val){
        prev = curr;
        curr = curr->next;
    }
    //not in the list
    if( curr->next == NULL){
        return;
    }

    prev->next = curr->next;
    free(curr);
}


void deleteNodeByPos(Node **head, int position){

    if( *head == NULL ){ return; }

    Node *curr = *head;
    if( position == 0 ){
        *head = curr->next;
        free(curr);
        return;
    }

    int count;
    for( count=0; curr!=NULL && count<position-1; count++){
        curr = curr->next;
    }
    //not in the list
    if( curr == NULL || curr->next == NULL){
        return;
    }

    Node *target = curr->next->next;
    free(curr->next);
    curr->next = target;
}

void reverse(Node **head){
    Node* prev = NULL;
    Node* curr = *head;
    Node* next = NULL;
    while (curr != NULL){

        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

int main()
{
  Node *head = NULL;
  push( &head, 1);
  push( &head, 2);
  append( &head, 3);
  push( &head, 6);
  push( &head, 9);

  printf("\n Created Linked list is: ");
  printList(head);

  deleteNode(&head, 6);
  printf("\n After Deletion Linked list is: ");
  printList(head);

  deleteNodeByPos(&head, 0);
  printf("\n After Deletion Linked list By Position is: ");
  printList(head);
  return 0;
}

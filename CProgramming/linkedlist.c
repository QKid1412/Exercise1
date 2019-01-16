#include <stdio.h>
#include <malloc.h>

typedef struct node {
    int value;
    struct node* next;
}node;

node *search_list(node *list, int n){
    node *temp;

    for(temp = list; temp != NULL; temp = temp->next){

        if(temp->value == n)
            return temp;
    }
    return NULL;
}

void print_list(node *root)
{
	node *lp=root;
	while(lp) {
		printf("%d\n", lp->value);
		lp=lp->next;
	}
}

// use double pointer to directly change head and dont have to return
void del_item(node **root, int val){
    if(*root == NULL){
        printf("Empty List");
        return;
    }

    node *tmp = *root;
    if(tmp->value == val){
        *root = *root->next;
        free(tmp);
        return;
    }

    node *curr = *root;
    node *prev = *root;

    while(curr->next != NULL && curr->value !=val){
        prev = curr;
        curr = curr->next;
    }
    if( curr->next == NULL){
        printf("invalid");
        return;
    }
    prev->next = curr->next;
    free(curr);
}
node * deleteK(node *head,int k)
{
  // Delete every kth node
  if(head == NULL || k < 1){ return head;}

  if(k == 1){
      while(head->next != NULL){
          node *del = head;
          head = head->next;
          free(del);
      }
      return NULL;
  }

  node *curr = head;

  int count = 1;

  while(curr != NULL && curr->next != NULL){
      if(count != k-1){
          curr = curr->next;
          count++;
      }else{
          node *del = curr->next;
          curr->next = curr->next->next;
          curr = curr->next;
          free(del);
          count = 1;
      }
  }

  return head;
}

// Move Zeros to the front of the list
void moveZeroes(node **head)
{
    //Your code here
    node *curr = *head;
    node *prev;
    while(curr != NULL && curr->next != NULL){

        if (curr->next->data == 0){
            node *tmp = curr->next;
            curr->next = curr->next->next;
            tmp->next = *head;
            *head = tmp;
        }else{
            curr = curr->next;
        }

    }

}

// function should insert node at the middle
// of the linked list
node* insertInMiddle(node* head, int x)
{
	// Cpde here
	node *fast = head;
	node *slow = head;
	while(fast != NULL && fast->next != NULL){
	    fast = fast->next->next;
	    if(fast != NULL){
	        slow = slow->next;
	    }
	}
	node *insert = (Node *)malloc(sizeof(node));
	insert->data = x;
	insert->next = slow->next;
	slow->next = insert;

	return head;
}

// reverse list and return new head
node* reverse(node *head)
{
  // Your code here

  node *curr = head;
  node *prev = NULL;
  node *next;
  while(curr != NULL){
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
  }
  head = prev;
  return head;
}

// reverse every k nodes using recursion
node *reverseK(node *head, int k)
{
  // Complete this method

  node *curr = head;
  node *prev = NULL;
  node *next = NULL;
  int count = 0;

  while(curr != NULL && count < k ){
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
      count++;
  }
  if(next != NULL){
      head->next = reverseK(next, k);
  }

  return prev;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
/*
typedef struct node {
  double data;
  struct node *next;
} Node;
*/
// Write all your functions here.



bool IsEmpty(Node* head){
   if (head == NULL){
     return(true);
   }
   return(false);
}



void DisplayList(Node *head){
  if (head != NULL){
    printf("%d", head->data);
    DisplayList(head->next);
  }
  return;
}



Node* InsertNode(Node** phead, int index, double x){
  Node *curr = *phead;
  Node *new_Node;
  new_Node->data = x;
  new_Node->next = *phead;
  if (index == 0){
    new_Node->next = curr;
    return(new_Node);
  }
  Node *last  = NULL;
  while (index != 0){
    index -= 1;
    Node* temp = curr;
    curr = curr->next;
    last = temp;
    if (curr == NULL && index != 0){
      return(NULL);
    }
  }
  last->next = new_Node;
  new_Node->next = curr;
  return(new_Node);
}



int FindNode(Node* head, double x){
  int po = 1;
  do{
    if (head->data == x){
      return(po);
    }
    head = head->next;
    po += 1;
  } while(head != NULL);

  return 0;
}



int DeleteNode(Node** phead, double x){
   return 0;
}

// Testing all the functions:
int main(void) {
  Node* head = NULL;

  // Output: true
  printf("%s\n", IsEmpty(head) ? "true" : "false");

  // Must output an empty line:
  DisplayList(head);

  // Must output "insert failed":
  Node* result = InsertNode(&head, 20, 7);
  printf("%s\n", result == NULL ? "insert failed" : "insert succeeded");

  // Output: 0.000000 1.000000 2.000000 3.000000 4.000000
  for(int i = 0; i < 5; i++) {
    InsertNode(&head, i, i);
  }
  DisplayList(head);

  // Output: false
  printf("%s\n", IsEmpty(head) ? "true" : "false");

  // Output: 4.000000 3.000000 2.000000 1.000000 0.000000 0.000000 1.000000 2.000000 3.000000 4.000000
  for(int i = 0; i < 5; i++) {
    InsertNode(&head, 0, i);
  }
  DisplayList(head);

  // Output: 0.000000 is at position 5
  //         2.000000 is at position 3
  //         4.000000 is at position 1
  //         6.000000 is not in the list
  for(int i = 0; i < 7; i += 2) {
    int idx = FindNode(head, i);
    if(idx > 0) {
      printf("%f is at position %d\n", (double)i, idx);
    } else {
      printf("%f is not in the list\n", (double)i);
    }
  }

  return 0;
  // Output: inserted 10.000000
  //         4.000000 3.000000 2.000000 10.000000 1.000000 0.000000 0.000000 1.000000 2.000000 3.000000 4.000000
  Node *in = InsertNode(&head, 3, 10);
  printf("inserted %f\n", in->data);
  DisplayList(head);

  // Output: 4.000000 3.000000 2.000000 10.000000 1.000000 0.000000 1.000000 2.000000 3.000000 4.000000
  //         3.000000 2.000000 10.000000 1.000000 0.000000 1.000000 2.000000 3.000000 4.000000
  //         3.000000 2.000000 10.000000 1.000000 0.000000 1.000000 2.000000 3.000000
  DeleteNode(&head, 0); // Delete in the middle of the list.
  DisplayList(head);
  DeleteNode(&head, 4); // Delete at the front of the list.
  DisplayList(head);
  DeleteNode(&head, 4); // Delete at the end of the list.
  DisplayList(head);

  DestroyList(head);

  return 0;
}

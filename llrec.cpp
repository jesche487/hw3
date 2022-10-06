#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
  // if input list is NULL, set larger and smaller to null as well to cut off any excess garbage
  if(head == NULL) {
    smaller = larger = NULL;
    return;
  }

  // temp variable to allow for emptying of input list
  auto temp = head;
  head = NULL;
  // if curr val less than pivot, smaller points to current node 
  // and recursion is called on the next nodes for both temp and smaller
  if(temp->val <= pivot) {
    smaller = temp;
    llpivot(temp->next, smaller->next, larger, pivot);
  }
  // same logic as above except for larger and temp
  else {
    larger = temp;
    llpivot(temp->next, smaller, larger->next, pivot);
  }

  return;
}
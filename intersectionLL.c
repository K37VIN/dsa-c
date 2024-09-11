#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};


  Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
  }
  void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

  void findIntersection(Node *head1,  Node *head2) {
  struct Node * current1 = head1;
  struct Node * current2 = head2;
  if  (head1 == NULL || head2 == NULL) {
    return NULL;
  }
  int len1=0,len2=0;
  while (current1 != NULL) {
  len1++;
  current1 = current1->next;
  }

  while(current2 !=NULL){
    len2++;
    current2 = current2->next;
  }

  for(int i=0;i<len1;i++){
    for (int j=0;j<len2;j++){
      if (current1->data == current2->data) {
        insertNode(current1);
    }
  }}}
  

 int main(){
   insertNode(&head1, 1);
   insertNode(&head1, 2);
   insertNode(&head1, 3);
   insertNode(&head1, 4);
   insertNode(&head1, 5);

   insertNode(&head2, 6);
   insertNode(&head2, 7);
   insertNode(&head2, 8);
   insertNode(&head2, 4);
   insertNode(&head2, 5);



  return 0;
   
 }  





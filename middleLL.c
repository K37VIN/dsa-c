#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
};

int main(){
  struct Node *head;
  struct Node *ptr;
  ptr=(struct Node *)malloc(sizeof(struct Node));
  if (ptr==NULL){
        printf("Memory Allocation failed!");
        return 1;
      }
  printf("Enter the value of the node:");
  scanf("%d",&ptr->data);
  ptr->next=NULL;
  ptr->prev=NULL;
  head=ptr;
  
  char ch;
  printf("Do you want to enter more data: (Y/N)");
  scanf("%c",&ch);
  while (ch=='Y' || ch=='y'){
      struct Node *ptr1;
      ptr1=(struct Node *)malloc(sizeof(struct Node));
      if (ptr1==NULL){
        printf("Memory Allocation failed!");
        return 1;
      }
      printf("Enter the value of the node:");
      scanf("%d",&ptr1->data);
      ptr->next=ptr1;
      ptr1->next=NULL;
      ptr1->prev=ptr;
      ptr=ptr1;

      printf("Do you want to insert to enter more data: (Y/N)");
      scanf("%c",&ch);
  }


  struct Node *s=head;
  struct Node *f=head;
  while(f!=NULL && f->next!=NULL){
    s=s->next;
    f=f->next->next;
  }

  printf("The middle of the linked list is:");
  printf("%d",s->data);

  return 0;
}
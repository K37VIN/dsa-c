#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node*next;
};

int main(){
  struct Node *head=NULL;
  struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
  printf("Enter the value of the node:");
  scanf("%d",&ptr->data);
  ptr->next=NULL;
  ptr=head;
  char ch;
  printf("Do you want to enter more data?(Y/N)");
  scanf(" %c",&ch);
  while(ch=='Y'|| ch=='y'){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the value of the node:");
    scanf("%d",&node->data);
    node->next=NULL;
    ptr->next=node;
    ptr=node;
    printf("Do you want to enter more data?(Y/N)");
    scanf(" %c",&ch);
  }

struct Node* s=NULL;
struct Node* f=NULL;
while(f!=NULL && f->next!=NULL){
  s=s->next;
  f=f->next->next;
  if (s==f){
    printf("The loop is detected");
  }
  else{
    printf("The loop is not detected");
  }
}
  return 0;
}
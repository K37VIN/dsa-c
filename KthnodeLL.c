#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

int main(){

struct Node *head=NULL;
struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
printf("Enter the value of the node:");
scanf("%d",&ptr->data);
ptr->next=NULL;
head=ptr;
char ch;
printf("Do you want to enter more data?(Y/N)");
scanf(" %c",&ch);
while(ch=='Y'|| ch=='y'){
  struct Node *ptr1=(struct Node*)malloc(sizeof(struct Node));
  printf("Enter the value of the node:");
  scanf("%d",&ptr1->data);
  ptr1->next=NULL;
  ptr->next=ptr1;
  ptr=ptr1;
  printf("Do you want to enter more data");
  scanf(" %c",&ch);
}

int len=0;
struct Node*tm=head;
while(tm!=NULL){
  len+=1;
  tm=tm->next;
}

int k;
printf("Select the position from the last which you want to delete:");
scanf("%d",&k);
struct Node *container=NULL;
struct Node *temp=head;
int pos=len-k;
for (int i=0;i<pos;i++){
  temp=temp->next;
}
container=temp->next;
temp->next=container->next;
free(container);


printf("Resultant LinkedList:");
struct Node* point=head; 
while(point!=NULL){
  printf("%d->",point->data);
  point=point->next;
}
printf("NULL");
 
return 0;
}


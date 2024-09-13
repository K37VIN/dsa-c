#include<stdio.h>
#include<stdlib.h>

struct Node{
  char ch;
  int imp;
  struct Node* next;
};

int main(){
  struct Node *head=NULL;
  struct Node *ptr=(struct Node*)malloc(sizeof (struct Node));
  printf("Enter any grade from A-Z:");
  scanf(" %c",&ptr->ch);
  printf("Enter the weightage of the grade:");
  scanf("%d",&ptr->imp);
  ptr->next=NULL;
  head=ptr;
  char chr;
  printf("Do you want to want to enter more data:");
  scanf(" %c",&chr);
  while(chr=='Y'||chr=='y'){
     struct Node *ptr1=(struct Node*)malloc(sizeof (struct Node));
     printf("Enter any grade from A-Z:");
     scanf(" %c",&ptr1->ch);
     printf("Enter the weightage of the grade:");
     scanf("%d",&ptr1->imp);
     ptr1->next=NULL;
     ptr->next=ptr1;
     ptr=ptr1;
     printf("Do you want to enter more data:");  
     scanf(" %c",&chr);
    
     }
  
  
  struct Node* i = head;
  struct Node* j;
  int temp;

  while (i != NULL) {
      j = i->next;
      while (j != NULL) {
          if (i->imp > j->imp) {
              temp = i->imp;
              i->imp = j->imp;
              j->imp = temp;

              char temp_ch = i->ch;
              i->ch = j->ch;
              j->ch = temp_ch;
          }
          j = j->next;
      }
      i = i->next;
  }

  printf("Reordered  list: \n");
  struct Node* tmp=head;
  while(tmp!=NULL){
    printf ("%c %d\n",tmp->ch,tmp->imp);
    tmp=tmp->next;
  }

  return 0;
  }
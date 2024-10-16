#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void deletePrimes(struct Node** head);

struct Node{
  int data;
  struct Node* next;
  struct Node* prev;
};


int main(){
  struct Node* head=NULL;
  struct Node* ptr;
  ptr=(struct Node*)malloc(sizeof(struct Node));
  printf("Enter the value of the node:");
  scanf("%d",ptr->data);
  ptr->next=NULL;
  head=ptr;
  head->prev=NULL;
  char ch;
  printf("Do you want to insert more data?(Y/N):");
  scanf("  %c",&ch);
  while(ch=='Y'||ch=='y'){

    struct Node* ptr1=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the value of the node:");
    scanf("%d",ptr1->data);
    ptr1->next=NULL;
    ptr->next=ptr1;
    ptr1->prev=ptr;
    ptr=ptr1;

    printf("Do you want to insert more data?(Y/N):");
    scanf(" %c",&ch);
    

  }
deletePrimes(&head);

printf("Resultant List: \n");
struct Node* tmp=head;
while(tmp!=NULL){
  printf("%d ",tmp->data);
  tmp=tmp->next;
}

return 0;
}


void deletePrimes{
  struct Node* temp=head;
  struct Node* t1;
  while(temp!=NULL){
    if (isPrime(temp->data)){
      temp=temp->next;
    }
    else{
    t1=temp->next;
    temp=temp->next;
    temp->prev->next=temp->prev;
    free(temp);
    temp=t1;
  }  

  }
}

int isPrime(int n){
  int flag=0;
   for(int i=2;i<sqrt(n);i++){
      if (n%i==0){
        flag=1;
        break;
      }
    }
  if (flag==0) return 1;
  else return 0;
}
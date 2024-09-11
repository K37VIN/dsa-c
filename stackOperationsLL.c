#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

int main(){
  struct Node *top=NULL;
  char ch;
  printf("Do you want to perform some operations?(Y/N):");
  scanf(" %c",&ch);
  while(ch=='Y' || ch=='y'){
     int choice;
     printf("Stack Operations:");
     printf("1.Push\n 2.Pop\n 3.Traverse\n");
     printf("Enter your choice:");
     scanf("%d",&choice);
     switch(choice){
      case 1:
         int value;
         printf("Enter the value to be pushed:");
         scanf("%d",&value);
         push(value,&top);
         break;
      case 2:
         pop(&top);
         break;
      case 3:
         traverse(&top);
         break;  
         
  }

  printf("Do you want to continue with the operations?(Y/N):");
  scanf(" %c",&ch);
}
return 0;
}


struct Node createNode (int data){
  struct Node *node=(struct Node*)malloc(sizeof(struct Node));
  node->data=data;
  node->next=NULL;
  return node;
}

void push(int value,struct Node** top){
 struct Node* newNode=createNode(value);
 if(*top==NULL){
  *top=newNode;
 }
 
 else{
  struct Node *temp=*top;
  while(temp->next!=NULL){
    temp=temp->next;
}
   temp->next=newNode;
}
}

void pop(struct Node**  top){
  
  if(*top==NULL){
    return;
  }

  struct Node*tmp=*top;
  struct Node*ptr;
  if (tmp->next==NULL){
    free(tmp);
  }
  else{
     while(tmp->next->next!=NULL){
     tmp=tmp->next;
     }
     ptr=tmp->next;
     tmp->next=NULL;
     free(ptr);
  }
}

void traverse(struct Node *top){
  
  if(top==NULL){
    printf("Stack is empty\n");
    return;
  }

  while(top!=NULL){
     printf("%d ",top->data);
     top=top->next;
  }
}
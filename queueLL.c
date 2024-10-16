#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *next;
};

int isFull(){
  struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
  if(temp == NULL){
    free(temp); 
    return 1;
  }
  else{
    free(temp);
    return 0;
  }
}

int isEmpty(struct Node *f, struct Node* r){
  if (f == NULL && r == NULL){
    return 1;
  }  
  else{
    return 0;
  }
}

void enqueue(struct Node **f, struct Node **r, int value){
  if(isFull()){
    printf("Queue is full\n");
    return; 
  }
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->data = value;
  node->next = NULL;
  if(*f == NULL && *r == NULL){
    *f = *r = node;
  }
  else {
    (*r)->next = node;
    *r = node;
  }
}

void dequeue(struct Node **f, struct Node **r){
  if(isEmpty(*f, *r)){
    printf("Queue is empty. Nothing to dequeue\n");
    return; 
  }
  struct Node* tmp = *f;
  int val = tmp->data;
  *f = (*f)->next;
  free(tmp);
}

void traverse(struct Node *f){
  struct Node *ptr = f;
  while(ptr != NULL){
    printf("%d->", ptr->data);
    ptr = ptr->next;
  }
  printf("END\n");
}

int main(){
  struct Node* f = NULL;
  struct Node* r = NULL;
  char ch;
  int choice, value;
  printf("Do you want to perform any operations(Y/N):");
  scanf(" %c", &ch);
  while(ch == 'Y' || ch == 'y'){
    printf("1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.Traverse\n");
    printf("Enter your choice:");
    scanf("%d", &choice);
  
    switch(choice){
      case 1:
        printf("Enter the value that you want to insert in the queue:");
        scanf("%d", &value);
        enqueue(&f, &r, value);
        break;
      
      case 2:
        dequeue(&f, &r);
        break;

      case 3:
        traverse(f);
        break;

      default:
        printf("Wrong choice!\n");
        break;   
    }
    printf("Do you want to perform more operations:(Y/N)");
    scanf(" %c", &ch);
  }
  return 0;
}



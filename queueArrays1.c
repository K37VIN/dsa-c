#include <stdio.h>

#define  MAX 100

int queue[MAX];
int front = -1, rear = -1;

int isEmpty(){
  if (front==rear){
    return 1;
  }
  else return 0;
}

int isFull(){
  if (rear==MAX-1){
    return 1;
  }
  else return 0;
}

void enqueue(int value){
  if (isFull()){
    printf("Queue is full");
  }
  else{
    rear++;
    queue[rear]=value;
  }}

int dequeue(){
  if (isEmpty()){
    printf("Queue is empty");
  }
  else{
    int temp=queue[front];
    front++;
    return temp;
  }}

  void traverse(){
    if  (isEmpty()){
      printf("Queue is empty,so nothing to traverse.");
    }
  else{
    for(int i=front;i<=rear;i++){
      printf("%d ",queue[i]);
    }
  }
  }

  int main(){
    int choice,value;
    char ch;
    printf("Do you want to perform some operations?(Y/N)");
    scanf(" %c",&ch);
    while  (ch=='Y'|| ch=='y'){

      printf("1.Enqueue\n");
      printf("2.Dequeue\n");
      printf("3.Traverse\n");
      printf("Enter your choice");
      scanf("%d",&choice);

      switch(choice){
        case 1:
        printf("Enter the value you want to enqueue:");
        scanf("%d",&value);
        enqueue(value);
        break;

        case 2:
        dequeue();
        break;

        case 3:
        traverse();
        break;

        default:
        printf("Wrong Choice");
        break;
      }
      printf("Do you want to perform more operations?(Y/N)");
      scanf(" %c",&ch);
    }
    
    return 0;
  }
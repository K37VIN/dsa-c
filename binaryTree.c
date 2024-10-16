#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node* right;
  struct Node* left;
};

struct Node* createNode(int data);

int main(){
  struct Node*p=createNode(2);
  struct Node*p1=createNode(4);
  struct Node*p2=createNode(6);
  
  p->left=p1;
  p->right=p2;

  
  return 0;
  
}


struct Node* createNode(int data){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data=data;
  newNode->right=NULL;
  newNode->left=NULL;
  return newNode;
}
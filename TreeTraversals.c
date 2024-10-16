#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data);
void InOrder(struct Node* root);
void PreOrder(struct Node* root);
void PostOrder(struct Node* root);

int main(){
   struct Node* p=createNode(2);
   struct Node* p1=createNode(4);
   struct Node* p2=createNode(6);
   struct Node* p3=createNode(7);
   struct Node* p4=createNode(8);
   struct Node* p5=createNode(9);
   struct Node* p6=createNode(10);
   
   
   p->left=p1;
   p->right=p2;
   p1->left=p3;
   p1->right=p4;
   p2->left=p5;
   p2->right=p6;
   
   return 0;
}

struct Node* createNode(int data){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    if(node==NULL){
      printf("Memory allocation failed!\n");
    }
    node->data=data;
    node->right=NULL;
    node->left=NULL;
    return node;
}

//inorder traversal
void InOrder(struct Node* root){
    if(root!=NULL){
        InOrder(root->left);
        printf("%d",root->data);
        InOrder(root->right);
    }
}

//preorder traversal
void PreOrder(struct Node* root){
    if(root!=NULL){
        printf("%d",root->data);
        InOrder(root->left);
        InOrder(root->right);
    }
}

//postorder traversal
void PostOrder(struct Node* root){
    if(root!=NULL){
        InOrder(root->left);
        InOrder(root->right);
        printf("%d",root->data);
    }
}
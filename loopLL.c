#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};


 
int isLoop(struct Node**head)
struct Node* createNode(int data)
void insertAtEnd(struct Node** head,int data)


int main(){
  struct Node* head=NULL;
  int choice,value;
  char ch;
  printf("Do you want to perform operations on the linked list?(Y/N)");
  scanf(" %c",&ch);
  while(ch=='Y'||ch=='y'){
    printf("1.Insert data");
    printf("2.Check for loop");
    printf("Enter your choice");
    scanf("%d",&choice);
    switch(choice){
      case 1:
        printf("Enter the value you want to insert in the node:");
        scanf("%d",&value);
        insertAtEnd(&head,value);
        break;

      case 2:
        if (isLoop(&head)){
          printf("Contains Loop");
        }
        else{
          printf("Does not contain loop");
        }

        break;

        default:printf("Wrong Choice");
    }
    printf("Do you want to perform more operations?(Y/N)");
    scanf(" %c",&ch);
  }


  return 0;
}

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* ptr = createNode(data);
    if (*head == NULL) {
        *head = ptr;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
    }
}

int isLoop(struct Node** head){
  struct Node* f=*head;
  struct Node* s=*head;
  while (f!=NULL && f->next!=NULL){
    s=s->next;
    f=f->next->next;
    if (s==f){
      return 1;
    }
  }
    return 0;
  }


#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *next;
};

int main() {
    struct Node *ptr;
    struct Node *head = NULL;

    ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    head = ptr; 
    printf("Enter the value: ");
    scanf("%d", &ptr->data);
    ptr->next = NULL;

    char ch;
    printf("Do you want to store more data (Y/N): ");
    scanf(" %c", &ch); 

    while (ch == 'Y' || ch == 'y') {
        struct Node *ptr1;
        ptr1 = (struct Node *)malloc(sizeof(struct Node));
        if (ptr1 == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        printf("Enter the value: ");
        scanf("%d", &ptr1->data);
        ptr1->next = NULL;
        ptr->next = ptr1;
        ptr = ptr1;

        printf("Do you want to store more data (Y/N): ");
        scanf(" %c", &ch); 
    }
     
     int x;
     printf("Enter the value for partition:")
     scanf("%d",&x);
     struct Node *tmp=head;
     struct Node *list1=NULL;
     struct Node *list2=NULL;
     while (tmp!=NULL){
        if (tmp<x){
          insertEnd(&list1,tmp);
        }
        if (tmp>x){
          insertEnd(&list2,tmp);
        }
      tmp=tmp->next;
      
     }
     






    return 0;
}


void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


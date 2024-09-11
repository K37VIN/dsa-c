#include <stdio.h>
#include <stdlib.h>

struct Node {
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

  
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("END\n");

    
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter the value: ");
    scanf("%d", &node->data);
    
    struct Node *tmp=head;
    while(tmp->next!=NULL){
      tmp=tmp->next;
    }
    tmp->next = node;
    node->next=NULL;

  
    temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("END\n");

    return 0;
}

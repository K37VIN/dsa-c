#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};


void printList(struct Node *head) {
    struct Node *temp = head;
    printf("The list is: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void swapNodes(struct Node **head_ref, int x, int y) {
    if (x == y) return;

    struct Node *prevX = NULL, *currX = *head_ref;
    while (currX && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }

    struct Node *prevY = NULL, *currY = *head_ref;
    while (currY && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    if (!currX || !currY) return;

  
    if (prevX) prevX->next = currY;
    else *head_ref = currY;

  
    if (prevY) prevY->next = currX;
    else *head_ref = currX;


    struct Node *temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;


    temp = currX->prev;
    currX->prev = currY->prev;
    currY->prev = temp;

    if (currX->next) currX->next->prev = currX;
    if (currY->next) currY->next->prev = currY;
}

int main() {
    struct Node *head = NULL;
    struct Node *ptr;
    
    ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("Memory Allocation failed!");
        return 1;
    }
    
    printf("Enter the value of the node: ");
    scanf("%d", &ptr->data);
    ptr->next = NULL;
    ptr->prev = NULL;
    head = ptr;

    char ch;
    printf("Do you want to enter more data? (Y/N): "); 
    scanf("%c", &ch);
    
    while (ch == 'Y' || ch == 'y') {
        struct Node *ptr1;
        ptr1 = (struct Node *)malloc(sizeof(struct Node));
        if (ptr1 == NULL) {
            printf("Memory Allocation failed!");
            return 1;
        }
        
        printf("Enter the value of the node: ");
        scanf("%d", &ptr1->data);
        ptr->next = ptr1;
        ptr1->next = NULL;
        ptr1->prev = ptr;
        ptr = ptr1;

        printf("Do you want to enter more data? (Y/N): ");
        scanf("%c", &ch);
    }

    printList(head);

    int x, y;
    printf("Enter the values of the nodes to swap: ");
    scanf("%d %d", &x, &y);
    swapNodes(&head, x, y);
    
    printList(head);

    struct Node *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}



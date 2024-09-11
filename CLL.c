#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *ptr = NULL;
    struct Node *node = NULL;
    char ch;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("Memory Allocation failed!");
        return 1;  
    }
    printf("Enter the value of the node: ");
    scanf("%d", &ptr->data);
    ptr->next = NULL;
    head = ptr;
    printf("Do you want to enter more data? (Y/N): ");
    scanf(" %c", &ch); 

    while (ch == 'Y' || ch == 'y') {
        node = (struct Node *)malloc(sizeof(struct Node));
        if (node == NULL) {
            printf("Memory Allocation failed!");
            return 1; 
        }
        printf("Enter the value of the node: ");
        scanf("%d", &node->data);
        node->next = NULL;
        
        ptr->next = node;
        ptr = node;

        printf("Do you want to enter more data? (Y/N): ");
        scanf(" %c", &ch); 
    }
    ptr->next = head;
    struct Node *temp = head;
    do {
        printf("%d->", temp->data);
        temp = temp->next;
    } while (temp != head);

    return 0;
}

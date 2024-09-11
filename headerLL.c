#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    
    struct Node *start = (struct Node*)malloc(sizeof(struct Node));
    if (start == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    start->next = NULL;

    struct Node *ptr = start;

    char ch;
    printf("Do you want to enter data (Y/N): ");
    scanf(" %c", &ch);

    while (ch == 'Y' || ch == 'y') {
        struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
        if (newnode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        printf("Enter the value of the node: ");
        scanf("%d", &newnode->data); 
        newnode->next = NULL;

        
        ptr->next = newnode;
        ptr = newnode;

        printf("Do you want to enter more data (Y/N): ");
        scanf(" %c", &ch); 
    }


    printf("Header LinkedList: ");
    struct Node* tm = start->next;
    while (tm != NULL) {
        printf("%d -> ", tm->data);
        tm = tm->next;
    }
    printf("NULL\n");

    struct Node* tempNode;
    while (start != NULL) {
        tempNode = start;
        start = start->next;
        free(tempNode);
    }

    return 0;
}



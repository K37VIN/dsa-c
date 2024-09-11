#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *ptr = NULL;

    ptr = (struct Node *)malloc(sizeof(struct Node));
    head = ptr;

    printf("Enter the value: ");
    scanf("%d", &ptr->data);
    ptr->next = NULL;

    char ch;
    printf("Do you want to enter another data? (Y/N): ");
    scanf(" %c", &ch);

    while (ch == 'Y' || ch == 'y') {
        struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter the value: ");
        scanf("%d", &ptr1->data);
        ptr1->next = NULL;

        ptr->next = ptr1;
        ptr = ptr1;

        printf("Do you want to enter another data? (Y/N): ");
        scanf(" %c", &ch);
    }

    
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("END\n");

    
    struct Node *max = head;
    struct Node *tmp = head;
    while (tmp != NULL) {
        if (tmp->data > max->data) {
            max = tmp; 
        }
        tmp = tmp->next; 
    }
    printf("Max: %d\n", max->data);

    return 0;
}

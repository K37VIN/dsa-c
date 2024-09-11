#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertAtPosition(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    if (*head == NULL || position == 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        for (int i = 0; i < position - 1; i++) {
            if (current->next == NULL) {
                printf("Position out of range\n");
                return;
            }
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}


void deleteAtPosition(Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position == 0) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    } else {
        Node* current = *head;
        for (int i = 0; i < position - 1; i++) {
            if (current->next == NULL) {
                printf("Position out of range\n");
                return;
            }
            current = current->next;
        }
        if (current->next == NULL) {
            printf("Position out of range\n");
            return;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}


int countNodes(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}


void traverse(Node* head) {
    while (head != NULL) {
        printf("%d-> ", head->data);
        head = head->next;
    }
    printf("\n");
}


void reverse(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main() {
    Node* head = NULL;
    int choice, data, position;
    while (1) {
        printf("1. Insert a node at specific position\n");
        printf("2. Delete a node at specific position\n");
        printf("3. Count nodes\n");
        printf("4. Traverse the linked list\n");
        printf("5. Reverse the linked list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 2:
                printf("Enter the position: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 3:
                printf("Number of nodes: %d\n", countNodes(head));
                break;
            case 4:
                traverse(head);
                break;
            case 5:
                reverse(&head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
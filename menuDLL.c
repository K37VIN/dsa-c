#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data);
void insertAtPosition(Node** head, int data, int position);
void deleteAtPosition(Node** head, int position);
void traverseList(Node* head);
void menu();

int main()  {
    menu();
    return 0;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtPosition(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    if (position < 1) {
        printf("Invalid position. Position should be >= 1.\n");
        free(newNode);
        return;
    }
    if (position == 1) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
    } else {
        Node* current = *head;
        int count = 1;
        while (current != NULL && count < position - 1) {
            current = current->next;
            count++;
        }
        if (current == NULL) {
            printf("Position out of bounds.\n");
            free(newNode);
        } else {
            newNode->next = current->next;
            if (current->next != NULL) {
                current->next->prev = newNode;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }
    printf("List after insertion:\n");
    traverseList(*head);
}

void deleteAtPosition(Node** head, int position) {
    if (position < 1 || *head == NULL) {
        printf("Invalid position or empty list.\n");
        return;
    }
    Node* temp = *head;
    if (position == 1) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
    } else {
        int count = 1;
        while (temp != NULL && count < position) {
            temp = temp->next;
            count++;
        }
        if (temp == NULL) {
            printf("Position out of bounds.\n");
        } else {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            free(temp);
        }
    }
    printf("List after deletion:\n");
    traverseList(*head);
}


void traverseList(Node* head) {
    Node* current = head;
    if (current == NULL) {
        printf("List is empty.\n");
    } else {
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

void menu() {
    Node* head = NULL;
    int choice, data, position;
    while (1) {
        printf("\nDoubly Linked List Operations Menu:\n");
        printf("1. Insert an element at a specific position\n");
        printf("2. Delete an element from a specific position\n");
        printf("3. Traverse the list\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 2:
                printf("Enter the position to delete from: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 3:
                traverseList(head);
                break;
            case 4:
                printf("Successfully Exited!\n");
                while (head != NULL) {
                    Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                return;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }
}

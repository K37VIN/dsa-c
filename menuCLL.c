#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data);
void insertAtPosition(Node** head, int data, int position);
void deleteAtPosition(Node** head, int position);
void traverseList(Node* head);
void reverseList(Node** head);
void menu();


int main() {
    menu();
    return 0;
}


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
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

    if (*head == NULL) {
        if (position == 1) {
            newNode->next = newNode;  
            *head = newNode;
        } else {
            printf("Position out of bounds in an empty list.\n");
            free(newNode);
        }
        return;
    }

    Node* current = *head;
    int count = 1;

    if (position == 1) {
        newNode->next = *head;
        Node* temp = *head;
        if (temp != NULL) {
            while (temp->next != *head) {
                temp = temp->next;
            }
            temp->next = newNode;
        } else {
            newNode->next = newNode;
        }
        *head = newNode;
    } else {
        while (current->next != *head && count < position - 1) {
            current = current->next;
            count++;
        }
        if (count == position - 1) {
            newNode->next = current->next;
            current->next = newNode;
        } else {
            printf("Position out of bounds.\n");
            free(newNode);
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
    Node* prev = NULL;
    int count = 1;

    if (position == 1) {
        if (temp->next == *head) {
            free(temp);
            *head = NULL;
        } else {
            prev = *head;
            while (prev->next != *head) {
                prev = prev->next;
            }
            *head = (*head)->next;
            prev->next = *head;
            free(temp);
        }
    } else {
        while (temp->next != *head && count < position) {
            prev = temp;
            temp = temp->next;
            count++;
        }
        if (count == position) {
            prev->next = temp->next;
            free(temp);
        } else {
            printf("Position out of bounds.\n");
        }
    }

    printf("List after deletion:\n");
    traverseList(*head);
}


void traverseList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}


void reverseList(Node** head) {
    if (*head == NULL || (*head)->next == *head) {
        printf("List is empty or has only one element, no reversal needed.\n");
        return;
    }

    Node *prev = NULL, *current = *head, *next = NULL;
    Node *last = *head;

    
    while (last->next != *head) {
        last = last->next;
    }


    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != *head);

    *head = prev;
    last->next = *head; 

    printf("List after reversal:\n");
    traverseList(*head);
}

void menu() {
    Node* head = NULL;
    int choice, data, position;
    while (1) {
        printf("\nCircular Linked List Operations Menu:\n");
        printf("1. Insert an element at a specific position\n");
        printf("2. Delete an element from a specific position\n");
        printf("3. Traverse the list\n");
        printf("4. Reverse the list\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
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
                reverseList(&head);
                break;
            case 5:
                printf("Exiting...\n");
                if (head != NULL) {
                    Node* temp = head;
                    Node* nextNode;
                    do {
                        nextNode = temp->next;
                        free(temp);
                        temp = nextNode;
                    } while (temp != head);
                }
                return;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    }
}

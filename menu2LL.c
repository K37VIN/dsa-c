#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data);
void insertEnd(struct Node** head, int data);
void searchElement(struct Node* head, int element);
void sortList(struct Node** head);
void reverseList(struct Node** head);
void printList(struct Node* head);
void freeList(struct Node* head);

int main() {
    struct Node *head = NULL;
    int choice, data, element;
    char ch;
    do {
        printf("Enter value to insert: ");
        scanf("%d", &data);
        insertEnd(&head, data);

        printf("Do you want to store more data (Y/N): ");
        scanf(" %c", &ch); 
    } while (ch == 'Y' || ch == 'y');

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Element at End\n");
        printf("2. Search Element\n");
        printf("3. Sort List\n");
        printf("4. Reverse List\n");
        printf("5. Print List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                printf("Linked List after insertion:\n");
                printList(head);
                break;

            case 2:
                printf("Enter element to search: ");
                scanf("%d", &element);
                searchElement(head, element);
                break;

            case 3:
                sortList(&head);
                printf("Linked List after sorting:\n");
                printList(head);
                break;

            case 4:
                reverseList(&head);
                printf("Linked List after reversing:\n");
                printList(head);
                break;

            case 5:
                printf("Linked List:\n");
                printList(head);
                break;

            case 6:
                freeList(head);
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
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

void searchElement(struct Node* head, int element) {
    int index = 0;
    while (head != NULL) {
        if (head->data == element) {
            printf("Element %d found at position %d.\n", element, index);
            return;
        }
        head = head->next;
        index++;
    }
    printf("Element %d not found in the list.\n", element);
}

void sortList(struct Node** head) {
    if (*head == NULL) return;

    struct Node* i = *head;
    struct Node* j;
    int temp;

    while (i != NULL) {
        j = i->next;
        while (j != NULL) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
}

void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}




#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


void insertNode(struct Node** head, int pos, int data);
void deleteNode(struct Node** head, int pos);
int countNodes(struct Node* head);
void traverseList(struct Node* head);

int main() {
    struct Node *head = NULL;
    struct Node *ptr = NULL;
    int data;
    char ch;

  
    do {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        printf("Enter the value: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }

        printf("Do you want to store more data (Y/N): ");
        scanf(" %c", &ch); 
    } while (ch == 'Y' || ch == 'y');

    int choice, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Node at Specific Position\n");
        printf("2. Delete Node from Specific Position\n");
        printf("3. Count Nodes\n");
        printf("4. Traverse Linked List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position to insert (0 for beginning): ");
                scanf("%d", &pos);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertNode(&head, pos, data);
                printf("Linked List after insertion:\n");
                traverseList(head);
                break;

            case 2:
                printf("Enter position to delete (0 for beginning): ");
                scanf("%d", &pos);
                deleteNode(&head, pos);
                printf("Linked List after deletion:\n");
                traverseList(head);
                break;

            case 3:
                printf("Total nodes: %d\n", countNodes(head));
                break;

            case 4:
                printf("Linked List elements:\n");
                traverseList(head);
                break;

            case 5:
                
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


void insertNode(struct Node** head, int pos, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (pos == 0) { 
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        for (int i = 0; temp != NULL && i < pos - 1; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position out of bounds.\n");
            free(newNode);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    printf("Node inserted successfully.\n");
}


void deleteNode(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (pos == 0) { 
        *head = temp->next;
        free(temp);
    } else {
        for (int i = 0; temp != NULL && i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position out of bounds.\n");
        } else {
            prev->next = temp->next;
            free(temp);
        }
    }
    printf("Node deleted successfully.\n");
}

int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void traverseList(struct Node* head) {
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

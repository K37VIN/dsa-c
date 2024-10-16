//You are given a linked list where each element in the list is a node and have an integer data. You need to add 1 to the number formed by concatinating all the list node numbers together and //return the head of the modified linked list. 

//Note: The head represents the first element of the given array.


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function declarations
struct Node* createNode(int data);
void insertAtEnd(struct Node** head, int data);
void traverse(struct Node* head);
void addOne(struct Node** head);

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* node = createNode(data);
    if (*head == NULL) {
        *head = node; // Use dereference operator
        return; // Early return
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
}

void traverse(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("END\n");
}

void addOne(struct Node**head){
  if (*head==NULL){
    printf("Operation not possible!");
  }

  struct Node* temp = *head;
  int carry=1;
  while(temp!=NULL){
    temp=temp->next;
  }
  temp->data+=carry;
  
  edgy
}


int main() {
    struct Node* head = NULL;
    int choice, value;
    char ch;

    printf("Do you want to perform operations on LL? (Y/N): ");
    scanf(" %c", &ch);
    while (ch == 'Y' || ch == 'y') {
        printf("1. Insert at End\n");
        printf("2. Add 1 to the number formed by concatenating all the list node numbers together\n");
        printf("3. Traverse the list\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 2:
                addOne(&head);
                break;
            case 3:
                traverse(head);
                break;
            default:
                printf("Invalid choice!\n");
        }
        printf("Do you want to perform more operations? (Y/N): ");
        scanf(" %c", &ch);
    }
    
    return 0;
}

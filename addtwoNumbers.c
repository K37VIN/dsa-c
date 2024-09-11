#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* appendNode(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct Node* addTwoLists(struct Node* head1, struct Node* head2) {
    struct Node* result = NULL;
    int carry = 0;

    while (head1 != NULL || head2 != NULL || carry != 0) {
        int sum = carry + (head1 ? head1->data : 0) + (head2 ? head2->data : 0);
        carry = sum / 10;
        result = appendNode(result, sum % 10);

        if (head1) head1 = head1->next;
        if (head2) head2 = head2->next;
    }

    return result;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d", node->data);
        node = node->next;
        if (node != NULL) {
            printf("->");
        }
    }
    printf("\n");
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    int n1, n2, data;

    // Input List 1
    printf("Enter the number of elements for list 1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        head1 = appendNode(head1, data);
    }

    // Input List 2
    printf("Enter the number of elements for list 2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        head2 = appendNode(head2, data);
    }

    // Display the two lists
    printf("List 1: ");
    printList(head1);

    printf("List 2: ");
    printList(head2);

    // Add the two lists
    struct Node* result = addTwoLists(head1, head2);

    // Display the result
    printf("Result: ");
    printList(result);

    return 0;
}

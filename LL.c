#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

int main() {
    struct Node *head;
    struct Node node1, node2, node3;

    
    node1.data = 20;
    node2.data = 30;
    node3.data = 40;


    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;


    head = &node1;

    struct Node *ptr = head;
    while (ptr != NULL) {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("END");
    return 0;
}


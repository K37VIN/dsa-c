#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *next;
};

void insertList(struct Node **head,int data,int pos){
  struct Node *node=(struct Node *)malloc(sizeof(struct Node));
  if (node==NULL){
    printf("Memory Allocation failed!");
    return -1;
  }
  node->data=data
  node->next=NULL;

  int count=1;
  struct Node *point=*head;
  while(count<pos-1 &&  point->next!=NULL){

    point=point->next;
    count+=1;
  }
  if (point==NULL){
    printf("Position out of Bounds!")
  }
  node->next=point->next;
  point->next=node;

  traverseList(&head);
}

void traverseList(struct Node *head){
  struct Node *tmp=head;
  while (tmp!=NULL){
    printf("%d->",tm->data);
    tmp=tmp->next;
  }
  printf("END\n");
}

int countNodes(struct Node **head){
  struct Node *tm=*head;
  int count=0;
  while(tm!=NULL){
    count+=1;
    tm= tm->next; 
    }
  return count;  
}

void deleteNodes(struct Node **head, int pos) {
  
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    if (*head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    if (pos == 1) {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct Node *t = *head;
    int cnt = 1;
    while (cnt < pos - 1) {
        if (t->next == NULL) {
            printf("Position is out of range\n");
            return;
        }
        t = t->next;
        cnt += 1;
    }

    if (t->next != NULL) {
        struct Node *temp = t->next;
        t->next = t->next->next;
        free(temp);
    } else {
        printf("Position is out of range\n");
    }
}






int main(){
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
}
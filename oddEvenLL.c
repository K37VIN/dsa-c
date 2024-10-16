#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *ptr;
    struct Node *head = NULL;

    ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    head = ptr; 
    printf("Enter the value: ");
    scanf("%d", &ptr->data);
    ptr->next = NULL;

    char ch;
    printf("Do you want to store more data (Y/N): ");
    scanf(" %c", &ch); 

    while (ch == 'Y' || ch == 'y') {
        struct Node *ptr1;
        ptr1 = (struct Node *)malloc(sizeof(struct Node));
        if (ptr1 == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        printf("Enter the value: ");
        scanf("%d", &ptr1->data);
        ptr1->next = NULL;
        ptr->next = ptr1;
        ptr = ptr1;

        printf("Do you want to store more data (Y/N): ");
        scanf(" %c", &ch); 
    }

    struct Node*temp=head;
    struct Node*oddTail=NULL;
    struct Node*evenTail=NULL;
    struct Node*oddHead;
    struct Node*evenHead;
    while (temp!=NULL){
        if(temp->data%2!=0){
            if(oddHead==NULL){
              oddHead=oddTail=temp;
            }
            else{
                oddTail->next=temp;
                oddTail=temp;
            }
        
        }
        else{
             if(evenHead==NULL){
              evenHead=evenTail=temp;
            }
            else{
                evenTail->next=temp;
                evenTail=temp;
            }
        }
    temp=temp->next;
    }
    

    if (oddHead==NULL){
        head=evenHead;
    }
    else if (oddHead!=NULL && evenHead==NULL){
        head=oddHead;
    }
    else{
        oddTail->next=evenHead;
        evenTail->next=NULL;
        head=oddHead;
    }
    struct Node *tmp = head;
    while (tmp != NULL) {
        printf("%d->", tmp->data);
        tmp = tmp->next;
    }
    printf("END\n");

return 0;
}
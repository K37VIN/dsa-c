#include <stdio.h>
#include <stdlib.h>

struct Employee {
    char name[50];      
    int id;
    float salary;
    struct Employee *next;
};

int main() {
    struct Employee *head = NULL; 
    struct Employee *ptr;

    ptr = (struct Employee *)malloc(sizeof(struct Employee));
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter the name of the employee: ");
    scanf(" %[^\n]s", ptr->name); 
    printf("Enter the id of the employee: ");
    scanf("%d", &ptr->id); 
    printf("Enter the salary of the employee: ");
    scanf("%f", &ptr->salary); 
    ptr->next = NULL; 

    head = ptr;

    struct Employee *last = ptr; 

    for (int i = 2; i <= 10; i++) {
        struct Employee *ptr1 = (struct Employee *)malloc(sizeof(struct Employee));
        if (ptr1 == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }

        printf("Enter the name of the employee: ");
        scanf(" %[^\n]s", ptr1->name); 
        printf("Enter the id of the employee: ");
        scanf("%d", &ptr1->id); 
        printf("Enter the salary of the employee: ");
        scanf("%f", &ptr1->salary); 
        ptr1->next = NULL;

        last->next = ptr1; 
        last = ptr1; 
    }


    struct Employee *max = head;
    struct Employee *temp = head;
    while (temp != NULL) {
        if (temp->salary > max->salary) {
            max = temp;
        }
        temp = temp->next;
    }

    printf("Employee details with highest salary:\n");
    printf("Name: %s\n", max->name);
    printf("Id: %d\n", max->id);
    printf("Salary: %.2f\n", max->salary); 

    return 0;
}

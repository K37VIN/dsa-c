#include <stdio.h>
#include <stdlib.h>

struct PolyNode {
    int coefficient;
    int exponent;
    struct PolyNode* next;
};


struct PolyNode* createNode(int coefficient, int exponent);
void insertNode(struct PolyNode** head, int coefficient, int exponent);
struct PolyNode* addPolynomials(struct PolyNode* poly1, struct PolyNode* poly2);
void printPolynomial(struct PolyNode* poly);
void freePolynomial(struct PolyNode* poly);

int main() {
    struct PolyNode *poly1 = NULL, *poly2 = NULL, *result = NULL;
    int choice, coef, exp;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Polynomial Term\n");
        printf("2. Add Two Polynomials\n");
        printf("3. Print Polynomial\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter polynomial number (1 or 2): ");
                int polyNum;
                scanf("%d", &polyNum);
                printf("Enter coefficient: ");
                scanf("%d", &coef);
                printf("Enter exponent: ");
                scanf("%d", &exp);
                if (polyNum == 1) {
                    insertNode(&poly1, coef, exp);
                } else if (polyNum == 2) {
                    insertNode(&poly2, coef, exp);
                } else {
                    printf("Invalid polynomial number.\n");
                }
                break;

            case 2:
                result = addPolynomials(poly1, poly2);
                printf("Resultant Polynomial: ");
                printPolynomial(result);
                freePolynomial(result);
                break;

            case 3:
                printf("Polynomial 1: ");
                printPolynomial(poly1);
                printf("Polynomial 2: ");
                printPolynomial(poly2);
                break;

            case 4:
                freePolynomial(poly1);
                freePolynomial(poly2);
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

struct PolyNode* createNode(int coefficient, int exponent) {
    struct PolyNode* newNode = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}


void insertNode(struct PolyNode** head, int coefficient, int exponent) {
    struct PolyNode* newNode = createNode(coefficient, exponent);
    struct PolyNode* temp = *head;
    struct PolyNode* prev = NULL;

    if (*head == NULL || (*head)->exponent < exponent) {
        newNode->next = *head;
        *head = newNode;
    } else {
    
        while (temp != NULL && temp->exponent >= exponent) {
            if (temp->exponent == exponent) {
                temp->coefficient += coefficient;
                free(newNode);
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        prev->next = newNode;
        newNode->next = temp;
    }
}


struct PolyNode* addPolynomials(struct PolyNode* poly1, struct PolyNode* poly2) {
    struct PolyNode* result = NULL;

    while (poly1 != NULL || poly2 != NULL) {
        int coef, exp;

        if (poly1 == NULL) {
            coef = poly2->coefficient;
            exp = poly2->exponent;
            poly2 = poly2->next;
        } else if (poly2 == NULL) {
            coef = poly1->coefficient;
            exp = poly1->exponent;
            poly1 = poly1->next;
        } else if (poly1->exponent == poly2->exponent) {
            coef = poly1->coefficient + poly2->coefficient;
            exp = poly1->exponent;
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exponent > poly2->exponent) {
            coef = poly1->coefficient;
            exp = poly1->exponent;
            poly1 = poly1->next;
        } else {
            coef = poly2->coefficient;
            exp = poly2->exponent;
            poly2 = poly2->next;
        }

        if (coef != 0) {
            insertNode(&result, coef, exp);
        }
    }

    return result;
}


void printPolynomial(struct PolyNode* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    while (poly != NULL) {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly != NULL && poly->coefficient > 0) {
            printf(" + ");
        }
    }
    printf("\n");
}


void freePolynomial(struct PolyNode* poly) {
    while (poly != NULL) {
        struct PolyNode* temp = poly;
        poly = poly->next;
        free(temp);
    }
}

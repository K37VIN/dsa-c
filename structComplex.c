#include <stdio.h>

struct ComplexNumber{
    int real; 
    int imaginary; 
};

void displayComplexNumber(struct ComplexNumber c){
    printf("%d + %di", c.real, c.imaginary);
}

void AddComplexNumbers(struct ComplexNumber c1, struct ComplexNumber c2){
    struct ComplexNumber sum; 
    sum.real = c1.real+c2.real; 
    sum.imaginary = c1.imaginary+c2.imaginary; 
    printf("\nSum of "); 
    displayComplexNumber(c1);
    printf(" and "); 
    displayComplexNumber(c2); 
    printf(" is "); 
    displayComplexNumber(sum); 
}

void MultiplyComplexNumbers(struct ComplexNumber* c1, struct ComplexNumber* c2){
    struct ComplexNumber product; 
    product.real = (c1->real*c2->real)-(c2->imaginary*c1->imaginary); 
    product.imaginary = (c1->real*c2->imaginary)+(c1->imaginary*c2->real); 
    printf("\nProduct of "); 
    displayComplexNumber(*c1);
    printf(" and "); 
    displayComplexNumber(*c2); 
    printf(" is "); 
    displayComplexNumber(product);  
}

int main(){
    
    printf("\nWelcome to Complex Number Operations.\nPlease select desired operation from the menu below"); 

    int choice = -1; 

    while(1){
        printf("\n\n1. Add two Complex Numbers\n2. Multiply two Complex Numbers\n3. Exit\n"); 
        printf("\nYour choice:");
        scanf("%d", &choice); 

        if(choice==3){
            break; 
        }

        struct ComplexNumber c1, c2;

        printf("Enter real and imaginary part of first complex number: \n"); 
        printf("Real part: "); 
        scanf("%d", &c1.real); 
        printf("Imaginary part: "); 
        scanf("%d", &c1.imaginary); 

        printf("Enter real and imaginary part of second complex number: \n"); 
        printf("Real part: "); 
        scanf("%d", &c2.real); 
        printf("Imaginary part: "); 
        scanf("%d", &c2.imaginary); 

        if(choice==1){
            AddComplexNumbers(c1, c2); 
        }

        if(choice==2){
            MultiplyComplexNumbers(&c1, &c2); 
        }

        

        printf("\n\nWhat do you want to do next?");
    }
}
#include <stdio.h>

// Function to print polynomial
void printPolynomial(int poly[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        if (poly[i] != 0) {
            if (i == 0)
                printf("%d", poly[i]);
            else if (i == 1)
                printf("%dx + ", poly[i]);
            else
                printf("%dx^%d + ", poly[i], i);
        }
    }
    printf("\n");
}

// Function to multiply two polynomials
void multiplyPolynomials(int poly1[], int size1, int poly2[], int size2, int result[]) {
    // Initialize result array
    for (int i = 0; i < size1 + size2 - 1; i++) {
        result[i] = 0;
    }

    // Multiply each term of first polynomial with each term of second polynomial
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            result[i + j] += poly1[i] * poly2[j];
        }
    }
}

int main() {
    // Define the first polynomial coefficients
    int poly1[] = {3, 2, 5}; // Represents 3 + 2x + 5x^2
    int size1 = sizeof(poly1) / sizeof(poly1[0]);

    // Define the second polynomial coefficients
    int poly2[] = {1, 4};    // Represents 1 + 4x
    int size2 = sizeof(poly2) / sizeof(poly2[0]);

    // Array to store the result of multiplication
    int result[size1 + size2 - 1];

    // Multiply the polynomials
    multiplyPolynomials(poly1, size1, poly2, size2, result);

    // Print the polynomials and the result
    printf("First Polynomial: ");
    printPolynomial(poly1, size1);
    
    printf("Second Polynomial: ");
    printPolynomial(poly2, size2);

    printf("Product Polynomial: ");
    printPolynomial(result, size1 + size2 - 1);

    return 0;
}

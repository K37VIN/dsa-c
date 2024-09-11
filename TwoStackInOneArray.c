#include <stdio.h>

int main() {
    int n, m;
    printf("Enter the length of the first stack: ");
    scanf("%d", &n);
    int stack1[n];
    int top1 = -1;
    int maxsize1 = n - 1;

    
    printf("Enter the length of the second stack: ");
    scanf("%d", &m);
    int stack2[m];
    int top2 = -1;
    int maxsize2 = m - 1;

    printf("Enter the number of elements to push into stack1 (up to %d): ", n);
    int num1;
    scanf("%d", &num1);
    if (num1 > n) {
        printf("Number of elements exceeds the stack size. Reducing to maximum allowed.\n");
        num1 = n;
    }
    for (int i = 0; i < num1; i++) {
        if (top1 < maxsize1) {
            top1++;
            int value;
            printf("Enter value %d for stack1: ", i + 1);
            scanf("%d", &value);
            stack1[top1] = value;
        } else {
            printf("Stack1 is full!\n");
            break;
        }
    }
    printf("Enter the number of elements to push into stack2 (up to %d): ", m);
    int num2;
    scanf("%d", &num2);
    if (num2 > m) {
        printf("Number of elements exceeds the stack size. Reducing to maximum allowed.\n");
        num2 = m;
    }
    for (int i = 0; i < num2; i++) {
        if (top2 < maxsize2) {
            top2++;
            int val;
            printf("Enter value %d for stack2: ", i + 1);
            scanf("%d", &val);
            stack2[top2] = val;
        } else {
            printf("Stack2 is full!\n");
            break;
        }
    }

    int arr1[n];
    int arr2[m];

    for (int i = 0; i <= top1; i++) {
        arr1[i] = stack1[top1 - i];
    }
    for (int i = 0; i <= top2; i++) {
        arr2[i] = stack2[top2 - i];
    }

    int l = num1 + num2;
    int arr[l];
    int k;


    for (k = 0; k <= top1; k++) {
        arr[k] = arr1[k];
    }

    for (int i = 0; i <= top2; i++) {
        arr[k + i] = arr2[i];
    }

    printf("Combined stack values: ");
    for (int i = 0; i < l; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

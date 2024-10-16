#include <stdio.h>

void printPolynomial(int arr[], int n){
    for(int i = n-1; i>=0; i--){
        if(arr[i]==0){
            continue; 
        }
        if(i==0){
            if(arr[i]<0){
                printf("%d", arr[i]); 
            }else{
                printf("+%d", arr[i]); 
            }
            continue; 
        }

        if(i==n-1){
            printf("%dx^%d", arr[i], i); 
            continue; 
        }

        if(arr[i]<0){
            printf("%dx^%d", arr[i], i); 
        }else{
            printf("+%dx^%d", arr[i], i); 
        }
    }
}

int main(){
    int n1, n2; 

    printf("Degree(highest power) of first polynomial: ");
    scanf("%d",&n1); 
    n1++;

    printf("Degree(highest power) of second polynomial: ");
    scanf("%d",&n2); 
    n2++;

    int p1[n1], p2[n2]; 

    printf("Enter the co-efficients of first polynomial: \nCo-efficient of\n"); 

    for(int i = n1-1; i>=0; i--){
        printf("x%d: ", i); 
        scanf("%d", &p1[i]); 
    }

    printf("Enter the co-efficients of second polynomial: \nCo-efficient of\n"); 

    for(int i = n2-1; i>=0; i--){
        printf("x%d: ", i); 
        scanf("%d", &p2[i]); 
    }

    int size = 0; 
    if(n1>n2){
        size=n1; 
    }else{
        size=n2; 
    }

    int sum[size]; 

    int k = 0; 

    while(k<n1&&k<n2){
        sum[k]=p1[k]+p2[k]; 
        k++; 
    }

    while(k<n1){
        sum[k]=p1[k]; 
        k++; 
    }

    while(k<n2){
        sum[k]=p2[k]; 
        k++; 
    }

    printf("The sum of "); 
    printPolynomial(p1, n1); 
    printf(" and "); 
    printPolynomial(p2, n2); 
    printf(" is "); 
    printPolynomial(sum, size); 
}.
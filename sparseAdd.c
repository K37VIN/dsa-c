#include <stdio.h>

int matrixInput(int n, int m, int arr[n][m]){
    int count=0; 
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            scanf("%d", &arr[i][j]); 
            if(arr[i][j]!=0){
                count++; 
            }
        }
    } 
    return count; 
}

void convertToTriplet(int n, int m, int count, int arr[n][m], int trip[count+1][3]){
    int k=1; 
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(arr[i][j]!=0){
                trip[k][0]=i; 
                trip[k][1]=j; 
                trip[k][2]=arr[i][j]; 
                k++;
            }
        }
    }
    trip[0][0]=n; 
    trip[0][1]=m; 
    trip[0][2]=count; 
}

void printMatrix(int n, int m, int arr[n][m]){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            printf("%d ", arr[i][j]); 
        }
        printf("\n"); 
    }
    printf("\n"); 
}

int main(){

    int n, m; 
    printf("Enter dimensions of matrices to be added: \n"); 
    printf("Row count: "); 
    scanf("%d", &n); 
    printf("Column count: "); 
    scanf("%d", &m); 

    int arr1[n][m], arr2[n][m];

    printf("Enter elements for first matrix: \n"); 
    int count1=matrixInput(n, m, arr1);
    
    printf("Enter elements for second matrix: \n"); 
    int count2=matrixInput(n, m, arr2); 
    
    int trip1[count1+1][3], trip2[count2+1][3];

    convertToTriplet(n, m, count1, arr1, trip1); 

    convertToTriplet(n, m, count2, arr2, trip2); 


    int i=1, j=1, k=1; 
    int sum[count1+count2+1][3]; 

    while(i<=count1&&j<=count2){
        if(trip1[i][0]==trip2[j][0]){
            if(trip1[i][1]==trip2[j][1]){
                sum[k][0]=trip1[i][0]; 
                sum[k][1]=trip1[i][1]; 
                sum[k][2]=trip1[i][2]+trip2[i][2]; 
                k++; 
                j++; 
                i++; 
            }else if(trip1[i][1]<trip2[j][1]){
                sum[k][0]=trip1[i][0]; 
                sum[k][1]=trip1[i][1]; 
                sum[k][2]=trip1[i][2]; 
                k++; 
                i++; 
            }else{
                sum[k][0]=trip2[j][0]; 
                sum[k][1]=trip2[j][1]; 
                sum[k][2]=trip2[j][2]; 
                k++; 
                j++; 
            }
        }else if(trip1[i][0]<trip2[j][0]){
            sum[k][0]=trip1[i][0]; 
            sum[k][1]=trip1[i][1]; 
            sum[k][2]=trip1[i][2]; 
            k++; 
            i++; 
        }else{
            sum[k][0]=trip2[j][0]; 
            sum[k][1]=trip2[j][1]; 
            sum[k][2]=trip2[j][2]; 
            k++; 
            j++; 
        }
    }

    while(i<=count1){
        sum[k][0]=trip1[i][0]; 
        sum[k][1]=trip1[i][1]; 
        sum[k][2]=trip1[i][2]; 
        k++; 
        i++; 
    }

    while(j<=count2){
        sum[k][0]=trip2[j][0]; 
        sum[k][1]=trip2[j][1]; 
        sum[k][2]=trip2[j][2]; 
        k++; 
        j++; 
    }

    sum[0][0]=n; 
    sum[0][1]=m; 
    sum[0][2]=k-1; 

    int sumMatrix[n][m]; 

    for(int a = 0; a<n; a++){
        for(int b = 0; b<m; b++){
            sumMatrix[a][b]=0; 
        }
    }

    for(int a=1; a<k; a++){
        sumMatrix[sum[a][0]][sum[a][1]] = sum[a][2]; 
    }

    printf("\n\nFirst Matrix: \n");
    printMatrix(n, m, arr1); 

    printf("First Matrix Triplet Representation: \n");
    printMatrix(count1+1, 3, trip1);  

    printf("Second Matrix: \n");
    printMatrix(n, m, arr2);  

    printf("Second Matrix Triplet Representation: \n");
    printMatrix(count2+1, 3, trip2); 

    printf("Sum Matrix: \n");
    printMatrix(n, m, sumMatrix); 

    printf("Sum Matrix Triplet Representation: \n");
    printMatrix(k, 3, sum); 
   
}
#include <stdio.h>

void printMatrix(int n, int m, int arr[n][m]){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            printf("%d ", arr[i][j]); 
        }
        printf("\n"); 
    }
}

int main(){

    int n, m; 
    printf("Enter dimensions of matrix to be transposed: \n"); 
    printf("Row count: "); 
    scanf("%d", &n); 
    printf("Column count: "); 
    scanf("%d", &m); 

    int arr[n][m];

    printf("Enter elements for matrix: \n"); 
    int count=0; 
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            scanf("%d", &arr[i][j]); 
            if(arr[i][j]!=0){
                count++; 
            }
        }
    } 

    int trip[count+1][3];

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

   

    int transpose[count+1][3]; 
    
    for(int i= 0; i<count+1; i++){
        transpose[i][0]=trip[i][1];
        transpose[i][1]=trip[i][0];
        transpose[i][2]=trip[i][2];
    }
    transpose[0][0]=m;
    transpose[0][1]=n; 
    transpose[0][2]=count;  

    

    int transposeMatrix[m][n];

    for(int a = 0; a<m; a++){
        for(int b = 0; b<n; b++){
            transposeMatrix[a][b]=0; 
        }
    }

    for(int a=1; a<k; a++){
        transposeMatrix[transpose[a][0]][transpose[a][1]] = transpose[a][2]; 
    }

     
    k=1; 
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(transposeMatrix[i][j]!=0){
                transpose[k][0]=i; 
                transpose[k][1]=j; 
                transpose[k][2]=transposeMatrix[i][j]; 
                k++;
            }
        }
    } 

    printf("\n\nMatrix: \n");
    printMatrix(n,m,arr); 
    printf("\n"); 

    printf("Matrix Triplet Representation: \n");
    printMatrix(count+1, 3, trip); 
    printf("\n"); 

    printf("Transpose Matrix: \n");
    printMatrix(m,n,transposeMatrix); 
    printf("\n"); 

    printf("Transpose Matrix Triplet Representation: \n");
    printMatrix(count+1, 3, transpose); 
    printf("\n"); 
   
}
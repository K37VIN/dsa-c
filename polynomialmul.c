#include<stdio.h>


int main() {
  int n;
  int m;
    printf("Enter the size:");
    scanf("%d",&n);
    int poly1[n];
    printf("Enter the coefficients:");
    for (int i=0;i<n;i++){
       scanf("%d",&poly1[i]);
    } 

    printf("Enter the size:");
    scanf("%d",&m);
    int poly2[m];
    printf("Enter the coefficients:");
    for (int i=0;i<m;i++){
       scanf("%d",&poly2[i]);
    } 


    
    int result[n + m - 1];

   for (int i=0;i<n+m-1;i++){
     result[i]=0;
   }
   for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      result[i+j]+=poly1[i]*poly2[j];
    }
    
   }

 for (int i=0;i<n+m-1;i++){
    printf("%dx^%d",result[i],i);
 }   
  

    return 0;
}
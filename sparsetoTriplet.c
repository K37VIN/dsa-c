#include <stdio.h>

int main(){
int n;
int m;
printf("Enter the rows and columns of the matrix:")
scanf("%d%d",n,m);
int arr[n][m];
for (int i=0;i<n;i++){
  scanf("%d",arr[i][j]);
}
for (int i=0;i<n;i++){
  printf("%d",arr[i][j]);
}

int zero=0;
int count=0;
for (int i=0;i<n;i++){
  if (arr[i]!=0){
    count++;
  }
  else {
   int s[count+1][3];
s[0][0]=n;
s[0][1]=m;
s[0][2]=count;
int k=1;
for (int i=0;i<n;i++){
  for (int j=0;j<m;j++){
    if (arr[i][j]!=0){
      s[k][0]=i;
      s[k][1]=j;
      s[k][2]=arr[i][j];
      k++;
    }
  
  }
}

for (int i= 0;i<count+1;i++){
  for (int j=0;j<3;j++){
    printf("%d",s[i][j]);
  }
  } 
  } 
}



return 0;
  }
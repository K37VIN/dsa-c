#include<stdio.h>

int main(){
  int arr[5];
  printf("Enter the Elements:");
  for(int i=0;i<5;i++){
  scanf("%d",&arr[i]);
  }
  int hash[6];
  for (int i=0;i<6;i++){
    hash[arr[i]]+=1;
  }
  for (int i=0;i<6;i++){
    if (hash[i]==1){
      printf(i);
    }
  }merge
}
#include<stdio.h>
#include<stdlib.h>


int main(){
  int n;
  printf("Enter the number of elements:");
  scanf("%d",&n);
  int stack[n];
  int top=-1;
  int maxsize=n-1;
  char ch; 
  printf("Do you want to insert elements in the stack?(Y/N):");
  scanf(" %c",&ch);
  while (ch=='Y' || ch=='y'){
    int value;
    printf("Enter the element to be inserted:");
    scanf("%d",&value);
    if(top==maxsize){
      printf("Stack is full\n");
    }
    else{
      top++;
      stack[top]=value;
    }
   printf("Do you want to insert more data?(Y/N)");
   scanf(" %c",&ch); 
  }
  
  int temp;
  int k,l;
  for(k=0;k<=top;k++){
    for(l=0;l<=top-k-1;l++){
      if(stack[l]>stack[l+1]){
        temp=stack[l];
        stack[l]=stack[l+1];
        stack[l+1]=temp;
    }  
  }
}

printf("Stack after sorting:");
for(int i=0;i<=top;i++){
  printf("%d ",stack[i]);
}

return 0;
}
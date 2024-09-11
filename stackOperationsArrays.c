#include <stdio.h>
#include <stdlib.h>

int main(){
int stack[];
int n;
printf("Enter the number of elements in the stack:");
scanf("%d",&n);
stack[n]; 
int maxsize=n-1;
int top=-1;
int num;
char ch;
printf("Do you want to perform any functions:")
scanf("%c",&ch);

while(ch=='Y' || ch== 'y'){

printf("MENU:");
printf("\n1. Push");
printf("\n2. Pop");
printf("\n3. Seek");
printf("\n4. Traverse");
printf("\n\nEnter your choice:");
scanf("%d",&num);

if (num==1){
  push(stack,&top,maxsize);
}

if (num==2){
  pop(stack,&top);
}
if (num==3){
  int val=seek(stack,&top);
  printf("%d",val);
}
if(num==4){
  traverse(stack,&top,maxsize);
}

printf("Do you want to perform any more functions:")
scanf("%c",&ch);
}

return 0;
}



void push(int  stack, int *top, int maxsize){

  int value;
  printf("Enter the data that you want to insert:");
  scanf("%d",&value);
  if(*top==maxsize){
     printf("Overflow");
     return;
  }
  else{
     *top++;
     stack[*top]=value;
  }
}

int seek(int  stack, int *top){

  if (top==-1){
    return 9696;
  }
  else{
    return (stack[top]);
  }
  
}

void traverse(int stack,int *top,int maxsize){
  for(i=0;i<=*top;i++){
     printf("%d",stack[i]);   
  }
} 

void pop(int stack,int *top){
  if(*top==-1){
    printf("Underflow");
    return;
  }
  else{
    *top--;
  }
}


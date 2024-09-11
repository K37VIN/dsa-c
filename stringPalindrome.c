#include<stdio.h>
#include<stdlib.h>

void push(int stack,int *top,int maxsize){
  int value;
  printf("Enter the value to be pushed:");
  scanf("%d",&value);
  if (top==maxsize){
    printf("Stack Overflow");
    return;
  }
  top++;
  stack[top]=value;  
}

void pop(int stack,int *top){
  if (top==-1){
    printf("Stack Underflow");
    return;
  }
  else{
    printf("Store the elements of the stack in reverse order:");
    while(n>0){
      arr[stack[top--]];
      n--;
    }
  }
}


void PalindromeCheck(int stack[], int *top, int n) {
    int arr[n];
    int i;
    for (i = 0; i <= *top; i++) {
        arr[i] = stack[(*top) - i];
    }
    for (i = 0; i < n / 2; i++) {
        if (arr[i] != arr[n - i - 1]) {
            printf("Not a palindrome string\n");
            return;
        }
    }
    printf("The string is a palindrome string\n");
}


int main(){
int stack[]; 
int top=-1;
int stack[n];
int arr[n];
int n;
printf("Enter the value of n:");
scanf("%d",&n);
int maxsize=n-1;
char ch;
printf("Do you want to enter more data:");
scanf("%c",&ch);
int num;
while(ch=='Y'||ch=='y'){
 printf("Check Palindrome:\n");
 printf("\n1. Push");
 printf("\n2. Pop");
 printf("\n3. Check");
 printf("\n\nEnter your choice:");
 scanf("%d",&num);
 
if (num==1){
  push(stack,&top,maxsize);
}

if (num==2){
  pop(stack,&top);
}
if(num==3){
  PalindromeCheck(stack,&top,);
}

printf("Do you want to perform any more functions:")
scanf("%c",&ch);
}

return 0;
}


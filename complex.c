#include <stdio.h>
#include <stdlib.h>



typedef struct Complex{
  float real;
  float imag;
}complex;


int main(){
int ch;
complex c1,c2;

printf("Enter the real part of first number:");
scanf("%f",&c1.real);
printf("Enter the imaginary part of first number:");
scanf("%f",&c1.real);

printf("Enter the real part of second number:");
scanf("%f",&c2.real);
printf("Enter the imaginary part of second number:");
scanf("%f",&c2.real);
  
printf("Enter Your Choice:\n 1.Addition of Complex Numbers \n2.Multiplication of Complex Numbers");
scanf("%d",&ch);

switch(ch){
  case 1:
  printf("Enter the real part of first number:");
  scanf("%f",&c1.real);
  printf("Enter the imaginary part of first number:");
  scanf("%f",&c1.imag);
  printf("Enter the real part of second number:");
  scanf("%f",&c2.real);
  printf("Enter the imaginary part of second number:");
  scanf("%f",&c2.imag);
  result=addComplex(complex c1,complex c2);
  break;
  
  case 2:
  printf("Enter the real part of first number:");
  scanf("%f",&c1.real);
  printf("Enter the imaginary part of first number:");
  scanf("%f",&c1.imag);
  printf("Enter the real part of second number:");
  scanf("%f",&c2.real);
  printf("Enter the imaginary part of second number:");
  scanf("%f",&c2.imag);
  result=mulComplex(complex &c1,complex &c2);
  break;

}

void addComplex(complex c1,complex c2){
  complex temp;
  temp.real=c1.real+c2.real;
  temp.imag=c1.imag+c2.imag;
  System.out.println("Real part:%d",temp.real);
  System.out.println("Real part:%d",temp.imag);
}

void mulComplex(complex *c1,complex *c2){
  complex temp;
  temp.real=c1.real+c2.real;
  temp.imag=c1.imag+c2.imag;
  System.out.println("Real part:%d",temp.real);
  System.out.println("Real part:%d",temp.imag);
}


}
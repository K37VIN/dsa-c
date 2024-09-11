#include <stdio.h>

typedef struct Poly{
  float coeff;
  int exp;
}polynomial;
 

int main(){
  polynomial a[50],b[50],c[50];
  int deg1,deg2;
  int k=0,l=0,m=0;
  int i;

  printf("Enter the max degree of first polynomial:");
  scanf("%d",&deg1);
  printf("Enter the max degree of second polynomial:");
  scanf("%d",&deg2);

  for ( i=0;i<=deg1;i++){
    printf("Enter the coeficient of x^%d:",i);
    scanf("%f",&a[i].coeff);

    a[k++].exp=i;
  }

  for (i=0;i<=deg2;i++){
    printf("Enter the coeficient of x^%d:",i);
    scanf("%f",&b[i].coeff);

    b[l++].exp=i;
  }

  
printf("Expression 1=%.1f",a[0].coeff)
for ( i=1;i<=deg1;i++){
  printf(" + %.1fx^%d",a[i].coeff,a[i].exp);

}

printf("Expression 2=%.1f",b[0].coeff)
for ( i=1;i<=deg1;i++){
  printf(" + %.1fx^%d",b[i].coeff,b[i].exp);

}


if (deg1>deg2){
for( i=0;i<=deg2;i++){
  c[m].coeff=a[i].coeff+b[i].coeff;
  c[m].exp=a[i].exp; 
  m++;
}
for (i=deg2+1;i<=deg1;i++){
  c[m].coeff=a[i].coeff;
  c[m].exp=a[i].exp;
  m++;
}
}

if (deg1<deg2){
for( i=0;i<=deg1;i++){
  c[m].coeff=a[i].coeff+b[i].coeff;
  c[m].exp=b[i].exp; 
  m++;
}
for (i=deg1+1;i<=deg2;i++){
  c[m].coeff=a[i].coeff;
  c[m].exp=a[i].exp;
  m++;
}}

printf("Expression 3=%.1f",c[0].coeff)
for (i=1;i<m;i++){
  printf(" + %.1fx^%d",c[i].coeff,c[i].exp);

}

return 0;

}
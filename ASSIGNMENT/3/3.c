#include<stdio.h>  
#include<stdlib.h>
 int main()    
{    
system("cls");
int a,b;
printf("THIS IS A PROGRAM TO SWAP TWO VARIABLES WITHOUT USING THIRD VARIABLE.\n");
printf("\nGive a value for variable a : ") ;  
scanf("%d", &a); 
printf("\nGive a value for variable b : ") ;
scanf("%d", &b); 
printf("\nThe value of variables before swap is a = %d and b = %d.",a,b);      
a=a+b;//a=30 (10+20)    
b=a-b;//b=10 (30-20)    
a=a-b;//a=20 (30-10)    
printf("\n\nThe value of variables after swap is a = %d and b = %d.",a,b);      
int tt;
scanf("%d", &tt);
}   
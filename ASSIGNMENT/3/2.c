#include<stdio.h>    
#include<stdlib.h>  

int main()
{  
    long int n;
    int a[10],i;    
    system ("cls");  
    printf("This is a program to convert any number into binary, hexadecimal and octal form.\n");
    printf("\nEnter the number to convert: ");    
    scanf("%ld",&n); 
    long int n1  = n;  
    long int n2 = n; 


    for(i=0; n>0; i++)    
    {    
    a[i]=n%2;    
    n=n/2;    
    }    
	printf("\nEquivalent binary value of given decimal number : ");
    for(i=i-1; i>=0; i--)    
    {    
    printf("%d",a[i]);    
    }

    printf("\n");

    long int decimalNumber,remainder,quotient;
	int k=1,j,temp;
	char hexadecimalNumber[100];
	quotient = n1;
	while(quotient!=0){
		temp = quotient % 16;
		if( temp < 10)
		        temp =temp + 48; else
		        temp = temp + 55;
		hexadecimalNumber[k++]= temp;
		quotient = quotient / 16;
	}
	printf("\nEquivalent hexadecimal value of given decimal number : ");
	for (j = k -1 ; j> 0 ;j--)
	printf("%c",hexadecimalNumber[j]);

	printf("\n \n");
    
    long int remainder2, quotient2;
    int octalNumber[100], x = 1, y;
    quotient2 = n2;
    while (quotient2 != 0)
    {
        octalNumber[x++] = quotient2 % 8;
        quotient2 = quotient2 / 8;
    }
    printf("Equivalent octal value of given decimal number is : ");
    for (y = x - 1; y > 0; y--)
    printf("%d", octalNumber[y]);
    int tt;
    scanf("%d", &tt); 
}
#include<stdio.h>
#include<stdlib.h>
int main()
{
    system("cls");
    printf("THIS IS A PROGRAM TO PRINT SUM AND PRODUCT OF DIGITS OF A GIVEN NUMBER\n");
    printf("Enter Any Number : ");
    int t;
    scanf("%d", &t);
    int t1 = t;
    int digit_sum = 0;
    while(t>0){
        int last_digit = t%10;
        digit_sum = digit_sum + last_digit;
        t = t/10;
    }
    printf("The value of the sum of digits is : %d", digit_sum );
    //printf("\n");
    int digit_product=1;
    while(t1>0)
    {
        int last_digit = t1%10;
        digit_product=digit_product*last_digit;
        t1=t1/10;  
    }
    printf("\nThe value of product of digits is : %d", digit_product);
    int tt;
    scanf("%d", &tt);


}
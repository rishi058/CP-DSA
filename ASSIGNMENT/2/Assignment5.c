#include<stdio.h>                               //INCLUDING A LIBRARY

int main()                   
{
    int a;                                     //DECLARING DATA TYPES   
    float b, average;

    printf("Enter the 1st number: ");               //SYNTAX FOR OUTPUT
    scanf("%d", &a);                               //SYNTAX FOR INPUT
    printf("\nEnter the 2nd number: ");
    scanf("%f", &b);

    average=(a+b)/2;
    printf("\nThe division of the two numbers is: %.2f\n", average);

    int z;
    scanf("%d", &z);
    
    return 0;
     

}
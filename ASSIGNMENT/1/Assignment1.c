// Algebric Operations --> addition, subtraction, multiplication, division.

#include<stdio.h>                                         //INCLUDING A LIBRARY

int main()                   
{
    int x, addition, subtraction, multiplication;        //DECLARING DATA TYPES   
    float y, division;

    printf("Enter the 1st number: ");                     //SYNTAX FOR OUTPUT
    scanf("%d", &x);                                      //SYNTAX FOR INPUT
    printf("\nEnter the 2nd number: ");
    scanf("%f", &y);

    addition=x+y;                                                       //CREATING A FUNCTION
    printf("\nThe addition of two numbers is: %d\n", addition);

    subtraction=x-y;
    printf("\nThe substraction of two numbers is: %d\n", subtraction);

    multiplication=x*y;
    printf("\nThe multiplication of two number is: %d\n", multiplication);

    division=x/y;
    printf("\nThe division of the two numbers is: %.2f\n", division);

    int z;
    scanf("%d", &z);
    
    return 0;
     

}
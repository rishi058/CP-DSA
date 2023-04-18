#include <stdio.h>

int main()
{
    int dividend, divisor, quotient, remainder;

    printf("Enter the dividend: ");
    scanf("%d", &dividend);
    printf("\nEnter the divisor: ");
    scanf("%d", &divisor);

    quotient=dividend/divisor;
    remainder=dividend%divisor;

    printf("\nThe quotient is: %d", quotient);
    printf("\nThe remainder is: %d", remainder);

    int z;
    scanf("%d", &z);
    
    return 0;
}
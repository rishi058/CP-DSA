#include <stdio.h>

int main()
{
    int first, second, swapped;

    printf("Enter the 1st number: ");
    scanf("%d", &first);
    printf("\nEnter the 2nd number: ");
    scanf("%d", &second);

    swapped=first;
    first=second;
    second=swapped;

    printf("\nThe value of 1st number is %d and the value of 2nd number is %d", first, second);

    int z;
    scanf("%d", &z);
    return 0;
}
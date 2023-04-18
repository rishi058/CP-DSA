#include<stdio.h>

int main()
{
    int p ;
    float r, t, si ;
    printf("Enter the principle amount : ");
    scanf("%d", &p);
    printf("\nEnter the value of rate : ");
    scanf("%f", &r);
    printf("\nEnter the time in years : ");
    scanf("%f", &t);

    si = (p*r*t)/100;
    printf("\nThe value of simple intrest is : %.3f ", si);
    int i;
    scanf("%d",i);
    return 0;
}
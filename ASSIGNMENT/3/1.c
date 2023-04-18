#include<stdio.h>

int main()
{
    int celcius;
    float fahrenheit;
    printf("Enter the value of temperature in degree celcius : ");
    scanf("%d", &celcius);
    fahrenheit = ((1.8*celcius) + 32);
    printf("\nThe value of temperature in degree fahrenheit is : %.2f ", fahrenheit);
   
    int t;
    scanf("%d", &t);
}
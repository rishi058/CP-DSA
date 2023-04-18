#include<stdio.h>
#include<stdlib.h>

int main()
    {
        system("cls");
        printf("THIS IS A PROGRAM TO CALCULATE SUM OF THE GIVEN SERIES UPTO N TERMS\n");
        printf("1+2+4+7+11......\n");
        printf("Enter the value of N : ");
        int t;
        scanf("%d", &t);
        int sum = ((t*(t*t+5))/6);
        printf("\nSum is : %d",sum);
        int tt;
        scanf("%d", &tt);
    }


#include<stdio.h>
#include<stdlib.h>
int main()
{
    system("cls");
    int t;
    printf("Enter any Number : ");
    scanf("%d", &t);
    printf("\nAnswer 1.\n");
    for(int i = 1; i <= t; i++)
    { 
        for(int j = 1; j<=i; j++)
        {
            printf("%d", j);
            printf("  ");
        }
        printf("\n");
    }
    printf("\n");
    printf("\nAnswer 2.\n");
    for(int i = 1; i <= t; i++)
    {
        for(int k=t-i; k>0; k--){printf("  ");}
        for(int j = 1; j<=i; j++)
        {
            printf("%d",j);
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");
    printf("\nAnswer 3.\n");
      for(int i=1;i<=t;i++)
    {
        for(int j=1;j<=t-i;j++)
        {printf("   ");}
        for(int j=i;j>=1;j--)
        {printf(" %d ", j);}
        for(int j=2;j<=i;j++)
        {printf(" %d ", j);}
        printf("\n");
    }
    int tt;
    scanf("%d", &tt);

}
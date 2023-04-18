#include<stdio.h>
#include<stdlib.h>

int main()
{
    system("cls");
    printf("THIS IS A PROGRAM TO REVERSE A NUMBER AND CHECK IT IS A PALINDROME OR NOT\n");
    printf("Enter any number : ");
    int j;
    scanf("%d", &j);
    int k = j;
    int c=0;
    while(j != 0)
    {
        ++c;
        j = j/10;
    }
    int l = c;
    int ar1[c];
    int ar2[c];
    while( k != 0)
    {
        ar1[--c] = k%10;
        k = k/10;
    }
    for(int x = 0; x<l; x++)
    {
       ar2[l-1-x] = ar1[x];
    }
    printf("\nThe reverse of given number is : ");
    for(int x = 0; x<l; x++)
    {
        printf("%d", ar2[x]);
    }
    printf("\n");
    if(compareArray(ar1,ar2,l)==0){printf("\nYES, its a palindrome");}
    else{printf("\nNO, its not a palindrome");}
    int tt;
    scanf("%d", &tt);
}


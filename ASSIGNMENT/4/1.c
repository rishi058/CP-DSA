#include<stdio.h>
#include<stdlib.h>

int main()
{
    system("cls");
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    printf("\nEnter the elements of array : ");
    int array_1[n];
    for(int i=0; i<n; i++){scanf("%d",&array_1[i]);}
    printf("Enter the element for deletion : ");
        int a; scanf("%d", &a);
        int j=0;
        for(int i=0; i<n; i++){
            if(array_1[i]!=a){array_1[j]=array_1[i]; j++;}    
        }
        printf("Final array : ");
        for(int i=0; i<j; i++){
            printf("%d ", array_1[i]);
        }
    int tt;  scanf("%d", &tt);
    return 0;
}
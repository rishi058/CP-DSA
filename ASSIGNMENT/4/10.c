#include<stdio.h>
#include<stdlib.h>

void check(int num)    
{
    int count=0;
    for(int i=2;i<=num/2;i++){if(num%i==0){count++; break;}}
    if(count!=0){printf("NOT A PRIME");}
    else{printf("PRIME");}
}

int main()
{   system("cls");
    printf("Enter the size of array : ");
    int n; scanf("%d", &n);
    int arr[n];
    printf("\nEnter the elemants of array : ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i=0; i<n; i++){
        printf("%d = ",arr[i]); check(arr[i]);
        printf("\n");
    }
    int tt;  scanf("%d", &tt);
    return 0;
}
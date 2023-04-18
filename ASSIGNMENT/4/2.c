#include<stdio.h>
#include<stdlib.h>

int main()
{
    system("cls");
    int n;
    printf("Enter the size of array : ");
    scanf("%d", &n);
    printf("\nEnter the elements of array : ");
    int arr[n];
    for(int i=0; i<n; i++){scanf("%d", &arr[i]);}
    printf("\nEnter the number you want to insert : ");
    int a;
    scanf("%d", &a);
    printf("\nEnter the postion in which you want to insert : ");
    int b;
    scanf("%d", &b);
    b--;
    n++;
    int p = arr[b];
                for(int i=n-1;i>=b-1;i--){
                    arr[i+1]=arr[i];
                    arr[b]= a;
                    }
            printf("\nFinal array : ");
            arr[b]=p;
                for(int i=0; i<n; i++){
                    printf("%d ", arr[i]);
                    }
    int tt;  scanf("%d", &tt);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

void Binary_search(int arr[], int n, int x){

    int k = 0;
    for (int b = n/2; b >= 1; b /= 2) {
        while (k+b < n && arr[k+b] <= x) {k += b;}
    }

    if (arr[k] == x){printf("\nElement have been founded");}
    else {printf("\nThis element isn't in the List.");}

}

int main()
{
    system("cls");

    printf("Enter the size of List : ");
    int n; scanf("%d", &n);

    printf("\nEnter the elements of List in Sorted Order : ");
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the element you want to search for in the List : ");
    int k; scanf("%d", &k);

    Binary_search(arr, n, k);

    int h; scanf("%d", &h);
    

}
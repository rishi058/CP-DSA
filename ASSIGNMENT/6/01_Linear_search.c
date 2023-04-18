#include<stdio.h>
#include<stdlib.h>

void Linear_search(int arr[], int n, int k){
    int flag = 1;

    for(int i=0; i<n; i++){
        if(arr[i]==k){
            printf("\nElement is founded. Its position is %d.", i+1);
            flag--;
            break;
        }
    }

    if(flag){printf("\nThis element isn't in the List.");}

}

int main()
{
    system("cls");

    printf("Enter the size of List : ");
    int n; scanf("%d", &n);

    printf("\nEnter the elements of List : ");
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the element you want to search for in the List : ");
    int k; scanf("%d", &k);

    Linear_search(arr, n, k);

    int h; scanf("%d", &h);
}
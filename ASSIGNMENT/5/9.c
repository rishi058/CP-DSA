#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
 {
     int temp = *a;
     *a = *b;
     *b = temp;
 }

void reverse(int *arr[], int n){
    int b=(n/2);
    for(int i=0; i<b; i++){

        swap(&arr[i], &arr[n-i-1]);
    }
}

int main(){

    system("cls");

    int arr[7] = {11,22,33,44,55,66,77};

    printf("Initial value of array is : ");

    for(int i=0; i<7; i++){
        printf("%d ",arr[i]);
    }

    reverse(&arr, 7);

    printf("\nFinal value of array is : ");

    for(int i=0; i<7; i++){
        printf("%d ",arr[i]);
    }
    int tt; scanf("%d", &tt);

}
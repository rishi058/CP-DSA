#include<stdio.h>
#include<stdlib.h>

void read(int arr[], int n){
    int *ptr = &arr[0];
    for(int i=0; i<n; i++){
        printf("Value : %d || Address : %d\n",arr[i],ptr);
        *ptr++;
    }
}

int main(){

    system("cls");

    int arr[7] = {1,88,8,74,87,20,55};

    read(arr,7);
    int tt; scanf("%d", &tt);

}
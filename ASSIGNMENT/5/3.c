#include<stdio.h>
#include<stdlib.h>

int main(){
    
    system("cls");
    printf("Enter the size of array : ");
    int n; scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of array : ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Reverse order of array : ");
    for(int i=n-1; i>=0; i--){
        printf("%d ", arr[i]);
    }
    int tt; scanf("%d", &tt);

}
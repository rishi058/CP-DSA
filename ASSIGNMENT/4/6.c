#include<stdio.h>
#include<stdlib.h>

int small(int arr[], int n)
{
    int min = arr[0];    
    for (int i = 0; i < n; i++) {       
       if(arr[i] < min)    
           min = arr[i];    
    }      
    return min;
}

int big(int arr[], int n)
{
    int max=0;
    for(int i=0; i<n; i++){
        if(max<arr[i]){max=arr[i];}
    }
    return max;
}

int search(int arr[], int n, int r)
{   
    int count=0;
    for(int i=0; i<n; i++){
        if(arr[i]==r){count++;}
    }
    return count;
}

int main()
{   
    system("cls");
    int n;
    printf("Enter the size of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the elements of array : ");
    for(int i =0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("\nSmallest element is : %d", small(arr, n));
    printf("\n\nLargest element is : %d", big(arr, n));
    printf("\n\nEnter a element to search : ");
    int q; scanf("%d", &q);
    int y=search(arr,n,q);
    if(y==0){printf("\nThis element is not in array.");}
    else{printf("\nThis element occurs %d times in array.", y);}

    int tt;  scanf("%d", &tt);
    return 0;
}
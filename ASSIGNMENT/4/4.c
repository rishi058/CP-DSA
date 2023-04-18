#include<stdio.h>
#include<stdlib.h>
int main()
{   system("cls");
    printf("Enter the no. of rows of matrix: ");
    int r; scanf("%d", &r);
    printf("\nEnter the no. of columns of matrix : ");
    int c; scanf("%d", &c);
    printf("\nEnter the 2D martrix : \n");
    int arr[r][c];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
                scanf("%d", &arr[i][j]);
        }
    }
    int count=0;
    for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                    if(arr[i][j]==arr[j][i]){count++;}
            }
        }
    if(count==r*c){printf("\nThe given matrix is symetric.");}
    else{printf("\nThe given matrix is not symetric.");}
    int tt;  scanf("%d", &tt);
    return 0;
}
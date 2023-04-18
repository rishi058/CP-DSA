#include<stdio.h>
#include<stdlib.h>
int main()
{
    system("cls");
	printf("Enter the no. of rows of matrix_1: ");
    int r; scanf("%d", &r);
    printf("\nEnter the no. of columns of matrix_1: ");
    int c; scanf("%d", &c);
    printf("\nEnter the elements of martrix_1 : \n");
    int arr[r][c];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
                scanf("%d", &arr[i][j]);
        }
    }

    printf("\nEnter the no. of rows of matrix_2: ");
    int r1; scanf("%d", &r1);
    printf("\nEnter the no. of columns of matrix_2: ");
    int c1; scanf("%d", &c1);
    printf("\nEnter the elements of martrix_2 : \n");
    int arr1[r1][c1];
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
                scanf("%d", &arr1[i][j]);
        }
    }
    if(c!=r1){printf("\nGiven Matrices are not multiplicable");}
    else
    {
        printf("\nResult of (marix_1) * (matrix_2) : \n");
    int array[r][c1];
    for(int i=0; i<r; ++i){
        for(int j=0; j<c1; ++j){    
                array[i][j]=0;    
                for(int k=0; k<c1; k++){    
                array[i][j] = array[i][j] + arr[i][k]*arr1[k][j];    
                }    
            }    
    }    
   for (int i=0; i<r; ++i){
        for(int j=0; j<c1; ++j){
            printf("%d ",array[i][j] );
        }
        printf("\n");
    }    
    }
    int tt;  scanf("%d", &tt);
    return 0;
}
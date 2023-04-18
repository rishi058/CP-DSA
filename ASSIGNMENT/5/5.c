#include<stdio.h>
#include<stdlib.h>

int main(){
    
    system("cls");

    printf("Enter the no. of row or column of the square matrix : ");
    int n; scanf("%d", &n);
    int matrix[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    int sum=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
          if(i==j){sum+=matrix[i][j];}
        }
    }

    printf("\nSum of diagonal elements : %d", sum);
    int tt; scanf("%d", &tt);

}
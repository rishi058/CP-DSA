#include<stdio.h>
#include<stdlib.h>
int main()
{
    system("cls");
    printf("Enter elements of 3X3 matrix : \n");
    int a[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
                scanf("%d", &a[i][j]);
        }
    }
    float determinant = a[0][0] * ((a[1][1]*a[2][2]) - (a[2][1]*a[1][2])) -a[0][1] * (a[1][0]
   * a[2][2] - a[2][0] * a[1][2]) + a[0][2] * (a[1][0] * a[2][1] - a[2][0] * a[1][1]);
 
  printf("\nDeterminant of 3X3 matrix: %.3f", determinant);
 
  int tt;  scanf("%d", &tt);
    return 0;

}
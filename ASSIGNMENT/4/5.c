#include<stdio.h>
#include<stdlib.h>
int rev(int l)
{	int sum=0;
	while(l!=0){
		int j=l%10;
		l=l/10;
		sum+=j;
		sum=10*sum;
	}
	return sum/10;
}
int main()
{	
	system("cls");
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

	printf("\nFinal matrix : \n");
	for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
			int r=arr[i][j];
                printf("%d ", rev(r));
        }
		printf("\n");
    }
    int tt;  scanf("%d", &tt);
    return 0;
}
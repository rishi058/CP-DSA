#include<stdio.h>
#include<stdlib.h>

int array_1[50];
int main()
{   
    system("cls");
    printf("Enter the size of array : ");
    int n,x; scanf("%d", &n); x=n;
    printf("\nEnter the elements of array : ");
    for(int i=0; i<n; i++){
        scanf("%d", &array_1[i]);
    }
    int count=0, u;
    printf("\nEnter the no. of sequence(even) for deletion and insertion : ");
    int q; scanf("%d", &q);
    for(int i=0; i<q/2; i++)
    {
        count++;
        if(count>1){n = u+1;}
        printf("\nEnter the element for deletion : ");
        int a; scanf("%d", &a);
        int j=0;
        for(int i=0; i<n; i++){
            if(array_1[i]!=a){array_1[j]=array_1[i]; j++;}    
        }
        if(j==0){printf("UNDER FLOW"); break;}
        printf("Final array : ");
        for(int i=0; i<j; i++){
            printf("%d ", array_1[i]);
        }
        printf("\nEnter any element and its position to insert : ");
        int c,d; scanf("%d%d", &c, &d); d--;
        if(j==x){printf("OVER FLOW"); break;}
        int p = array_1[d];
            for(int i=j-1;i>=d-1;i--){
                array_1[i+1]=array_1[i];
                array_1[d]= c;
                }
        printf("\nFinal array : ");
        array_1[d]=p;
        for(int i=0; i<=j; i++){
            printf("%d ", array_1[i]);
        }
         u = j;
    }
    int tt; scanf("%d", &tt);
}
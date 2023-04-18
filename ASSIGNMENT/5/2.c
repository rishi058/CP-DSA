#include<stdio.h>
#include<stdlib.h>

void sum(){
    printf("Enter two integers you want to add : ");
    int a,b;
    scanf("%d%d", &a,&b);
    printf("\nSum (a+b) : %d",a+b);
}

void diff(){
    printf("Enter two integers you want you want to subtract : ");
    int a,b;
    scanf("%d%d", &a,&b);
    printf("\nDiffrence (a-b) : %d",a-b);
}

void prod(){
    printf("Enter two integers you want you want to multiply : ");
    int a,b;
    scanf("%d%d", &a,&b);
    printf("\nProduct (a*b) : %d",a*b);
}

int main(){

    system("cls");

    printf("Enter 1 to use Addition.");
    printf("\nEnter 2 to use Subtraction.");
    printf("\nEnter 3 to use Multiplication.\n");
    int x;
    scanf("%d",&x);
    if(x==1){sum();}
    else if(x==2){diff();}
    else if(x==3){prod();}
    int tt; scanf("%d", &tt);

}
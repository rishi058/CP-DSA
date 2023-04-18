#include<stdio.h>
#include<stdlib.h>

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);   //gcd using recursion
}
int main(){
    
    system("cls");

    printf("Enter two integers to find their LCM : ");
    int a,b;
    scanf("%d%d",&a,&b);
    int gcd1 = gcd(a,b);
    int lcm = (a*b)/gcd1;
    printf("\nThe LCM of obtained is : %d", lcm);

    int tt; scanf("%d", &tt);
}
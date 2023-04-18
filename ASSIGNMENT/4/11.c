#include<stdio.h>

void checkPrime(int num)    
{
    int count=0;
    for(int i=2;i<=num/2;i++){if(num%i==0){count++; break;}}
    if(count!=0){printf("NOT A PRIME");}
    else{printf("PRIME");}
}

int main() 
{
    int num;        //Declare a number
    printf("Enter the number\n");
    scanf("%d",&num);    //Initialize the num

    checkPrime(num);     //Function Call
    
    return 0;
}
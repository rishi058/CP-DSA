#include<stdio.h> 
#include<stdlib.h> 
void checkPrime(int num) 
{ 
int count=0; 
for(int i=2;i<=num/2;i++){if(num%i==0){count++; break;}} 
if(count!=0){printf("NOT A PRIME");} 
else{printf("PRIME");} 
} 
int main() 
{ 
system("cls"); 
printf("This is a program for checking a prime number.\n"); 
int a; 
printf("\nEnter any number b/w 1 to 100 : "); 
scanf("%d", &a); 
checkPrime(a); 
int tt; scanf("%d", &tt);
}

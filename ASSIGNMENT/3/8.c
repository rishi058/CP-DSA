#include <stdio.h>
#include <stdlib.h>
int find_count(int num,int dig)
{
    int rem, cnt;
    cnt=0;
    while(num>0){
        rem=num%10;
        if(rem==dig)
        cnt++;
        num/=10;}
    return cnt;
}
  
int main()
{
    system("cls");
    int num, digit, cnt;
    printf("Enter a number: ");
    scanf("%d",&num);
    printf("Enter digit to search: ");
    scanf("%d",&digit);
    cnt=find_count(num,digit);
    if(cnt==0){printf("This digit is not present in the given number.");} 
    else{printf("Total occurrence of digit is: %d", cnt);}
    int tt;
    scanf("%d", &tt);
}

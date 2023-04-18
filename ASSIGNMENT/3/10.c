#include<stdio.h>
#include<stdlib.h>

void display(int n)
{
    switch (n)
    {
    case(0) : printf("");break;
    case(1) : printf("one");break;
    case(2) : printf("two");break;
    case(3) : printf("three");break;
    case(4) : printf("four");break;
    case(5) : printf("five");break;
    case(6) : printf("six");break;
    case(7) : printf("seven");break;
    case(8) : printf("eight");break;
    case(9) : printf("nine");break;
    case(10) : printf("ten");break;
    case(11) : printf("eleven");break;
    case(12) : printf("twelve");break;
    case(13) : printf("thirteen");break;
    case(14) : printf("fourteen");break;
    case(15) : printf("fifteen");break;
    case(16) : printf("sixteen");break;
    case(17) : printf("seventeen");break;
    case(18) : printf("eighteen");break;
    case(19) : printf("nineteen");break;
    default:break;
    }
}

void display2(int n)
{
    switch (n)
    {
    case(2) : printf("twenty ");break;
    case(3) : printf("thirty ");break;
    case(4) : printf("fourty ");break;
    case(5) : printf("fifty ");break;
    case(6) : printf("sixty ");break;
    case(7) : printf("seventy ");break;
    case(8) : printf("eighty ");break;
    case(9) : printf("ninety ");break;
    default:break;
    }
}

int main()
{
    system("cls");
    printf("Enter Any Four Digit Number : ");
    int t;
    scanf("%d", &t);
    int a,b,c,d,e;
    d=t%10, c=(t/10)%10, b=(t/100)%10, a=(t/1000)%10 ;
    e = t%100;
    display(a);
    printf(" thousand ");
    display(b);
    if(b != 0){printf(" hundred ");}else {printf("");}
    if(c==0){printf("");}
    else if(c==1){display(e);}
    else if(c<=9 && c>1){display2(c);}
    if(c != 1){display(d);};
    int tt;
    scanf("%d", &tt);
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct students{int roll_no; char name[100]; int age; int fees;};

int main()
{
    system("cls");
    printf("Enter the Roll Number of Student : ");
    int t; scanf("%d", &t);
    printf("Enter the Name of Student : ");
    char nameee[100]; scanf("%s", &nameee);
    printf("Enter the Age of Student : ");
    int a; scanf("%d", &a);
    printf("Enter the Fees of Student : ");
    int f; scanf("%d", &f);

    
    struct students std1;
    std1.roll_no = 1;
    strcpy(std1.name, nameee);
    std1.age = a ;
    std1.fees = f;

    printf("\n\nThe Roll Number of Student : %d", std1.roll_no);
    printf("\nThe Name of Student : %s", std1.name);
    printf("\nThe Age of Student : %d", std1.age);
    printf("\nThe Fees of Student : %d", std1.fees);
    int tt; scanf("%d", &tt);

}
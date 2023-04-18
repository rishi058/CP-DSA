//call by reference using pointer
// for both c, c++
#include<stdio.h>

// Pointers is used to store address,

void f1(int *a )         //recieving address of x using pointer
{
    *a = 44;            //altering value of x direct from its adress
}

void f2(int b){
    b = 55;
}

int main()
{
    int x = 4;
    int y = 5;
    f1(&x);                 //sending address of x using &
    f2(y);                  // this will not work bcz f2() only copy the value to func. but not apply it and hence it will print y=5
    printf("x : %d", x);    //the value of x changes directly from its address therfore it will work
    printf("\nx : %d", y);

}
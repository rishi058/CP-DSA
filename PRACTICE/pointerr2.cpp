//call by reference using c++ refernce variable 
//only for c++
#include<stdio.h>
 
 void swap_pointer_var(int &a, int &b)
 {
     int temp = a;
     a = b;
     b = temp;
 }

 int main()
 {
     int x = 4, y = 5;
     printf("the value of x is %d and the value of y is %d", x, y);
     swap_pointer_var(x,y);
     printf("\nafter swaping \nthe value of x is %d and the value of y is %d", x, y);
   // printf("\nThe value of 1st number is %d and the value of 2nd number is %d", first, second);

 }
#include <bits/stdc++.h>

using namespace std;

int main()
{
int x = 4;
int *p_x = &x;       //declaring an address(pointer) for int 
cout << "Addr x : " << &x <<endl;        //using & to print address
cout << "Val *p_x: "<< p_x << endl;     //printing address
cout << "Val *p_x: "<< *p_x << endl;
*p_x = 5;      //changing value of x by accessing its address
cout << "x:" << x << endl;
cout << "p_x + 1: " <<p_x + 1 << endl; //increasing size of address 4 to 8 byte

int **p_p_x = &p_x;   //double pointer 
cout << "Addr p_x : " << &p_x <<endl;        //using & to print address
cout << "value p_p_x : " << p_p_x <<endl;        
cout << "value *p_p_x : " << *p_p_x <<endl;        
cout << "value **p_p_x : " << **p_p_x <<endl;        
**p_p_x = 7;
cout << "x : " << x <<endl;
}
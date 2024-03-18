#include <bits/stdc++.h>
using namespace std;

/*
n = 7
W = 15 (capacity of bag)

Objects      -->   1   2   3   4   5   6   7
Profits(P)   -->  10   5   15  7   6  18   3
Weigths(W)   -->   2   3   5   7   1   4   1

P/W          -->   5  1.3  3   1   6  4.5  3
X(0<=x<=1)   -->   x1  x2  x3  x4  x5  x6  x7

first sort(P/W) and start taking whole objects in bag (from max p/w to lesser), when the bag is nearly full &
next whole object isn't able to fit in bag, you should put the fraction of remaining object a/c to wt left in bag..


*/

int main()
{

}
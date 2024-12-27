#include <bits/stdc++.h>
using namespace std;

/*
There are 3 Rods A, B, C. Rod A has N discs of diffrent sizes in sorted manner in it.
You have to move all N discs from rod A to C (Use Rod B for convenience). but 3 given rules should be followed..

1. we can move only one disc at a time..
2. we can't put smaller discs below a larger disc..
3. disc's in Rod C also should be in sorted manner..

***********  APPROACH *********
WRITE THE STEPS TO MOVE 2 AND 3 DISC FROM ROD A TO C ON YOUR OWN..
FOLLOW THE SAME STEPS TO MOVE N DISCS...

--

A, B, C
A, C, B
C, B, A

TO MOVE DISKS FROM A TO B :
FIRST MOVE IT FROM A TO C,
THEN MOVE IT FROM C TO B,

*/


void solveTower(int n, char from='A', char to='B', char aux='C'){
    if(n == 0){return;}

    solveTower(n - 1, from, aux, to);

    cout<<"Move disk "<<n<<" from rod "<<from<<" to rod "<<to<<"\n";

    solveTower(n - 1, aux, to, from);
}

int main(){
    // Tower of Hanoi
    int n; cin>>n;
    solveTower(n);
    return 0;
}
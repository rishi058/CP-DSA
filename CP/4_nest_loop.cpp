// NESTED LOOP


#include <bits/stdc++.h>

using namespace std;

int main()
{

int i, j, k, b;
cin>>i;

for ( k=1 ; k <= i; k++)
{
    for(j=1; j<=k; ++j)
    {
    cout<<"*";
    }

    cout<<endl;
    }
cin>>b; cout<<++b;
}
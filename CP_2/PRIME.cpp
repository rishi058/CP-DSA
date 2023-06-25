#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
#define F(a,b,i) for (int i = a; i < b; i++)
#define RISHI ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

bool isPrime(int n){
    if(n==1){return false;}
    if(n==2 || n==3){return true;}
    if(n%2==0 || n%3==0){return false;}

    for(int i=5; i*i<=n; i+=6){
        if(n%i==0 || n%(i + 2)==0){
            return false;
        }
    }

    return true;
}


int32_t main()
{
    RISHI
    cout<<"000";

}
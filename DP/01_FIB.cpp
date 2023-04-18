#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

const int N = 1e7+9;
int dp[N];

int fib(int n){
    dp[0] = 0; dp[1] = 1;
    if(dp[n]!=-1){return dp[n];}
    return dp[n] = fib(n-1) + fib(n-2);
}

int func(int x){
    if(x==0){return 0;}
    if(x==1){return 1;}
    return func(x-1) + func(x-2);
}

int32_t main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;
    while(t--)
    {
        memset(dp, -1, sizeof(dp));
        cout<<fib(20); cout<<"\n";
        cout<<func(20);

    }

}
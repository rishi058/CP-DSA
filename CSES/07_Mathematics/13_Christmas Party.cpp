#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(v) v.begin(), v.end()
#define F(a,b,i) for (int i = a; i < b; i++)
#define Rev(a,b,i) for (int i = a; i >= b; i--)
#define RISHI ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
template <typename dStruct>
void print(dStruct& vName){for(auto &it : vName){cout<<it<<" ";} cout<<"\n";}
template <typename dStruct>
void print2(dStruct& vName){for(auto &it : vName){cout<<"{"<<it.first<<", "<<it.second<<"} ";} cout<<"\n";}
 
const int mod = 1e9 + 7;
#define inf LONG_LONG_MAX
#define Min LONG_LONG_MIN
 
typedef long double ld;
typedef vector<int> vi;
 
/*---------------------------------------->   MAGIC STARTS   <--------------------------------------------*/

/*
There are n children at a Christmas party, and each of them has brought a gift. The idea is that everybody will get a gift brought by someone else.
In how many ways can the gifts be distributed?
*/

int32_t main()
{
    RISHI
    int T = 1;
    // cin>>T;
    while(T--)
    {   
        int n; cin>>n;
        vi dp(n+1);
        dp[2] = 1;
 
        for(int i=3; i<=n; i++){
            dp[i] = (i-1) * (dp[i-1] + dp[i-2]) % mod;
        }
 
        cout<<dp[n];
    }
 
}

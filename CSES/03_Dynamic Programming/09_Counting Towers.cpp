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
our task is to build a tower whose width is 2 and height is n. You have an unlimited supply
of blocks whose width and height are integers.
For example, here are some possible solutions for n = 6:
*/

const int N = 1e6+1;
int dp[N][2];
 
/*
dp[x][0] = both below tile are free   --> 5 more possiblities
dp[x][1] = both below tile are fused  --> 3 more possiblities
*/
 
// MORE REALISTIC
void precompute(){
    dp[1][0] = 1;       // Achieved practically
    dp[1][1] = 1;
    for(int i=2; i<N; i++){
        dp[i][0] = ((dp[i-1][0] * 4)%mod + dp[i-1][1]%mod) %mod;
        dp[i][1] = (dp[i-1][0]%mod + (2*dp[i-1][1])%mod) %mod;
    }
}
 
int32_t main()
{
    RISHI
    precompute();
    int T; cin>>T;
    while(T--)
    {
        int n; cin>>n;
        cout<<(dp[n][1] + dp[n][0])%mod<<"\n";
    }
 
}
 

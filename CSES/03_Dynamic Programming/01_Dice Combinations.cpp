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

Your task is to count the number of ways to construct sum n by throwing a dice one or more
times. Each throw produces an outcome between 1 and 6.

For example, if n = 3, there are 4 ways:
•1+1+1
•1+2
•2+1
•3

Constraints
• 1 < n < 10^6

*/

vector<int> dp;
 
int solve(int sum){
    if(sum<0){return 0;}
    if(dp[sum]!=-1){return dp[sum];}
    int ways = 0;
    for(int i=1; i<=6; i++){
        ways = (ways+solve(sum-i))%mod;
    }
    return dp[sum] = ways;
}
 
int32_t main()
{
    RISHI
    int sum; cin>>sum;
    dp.resize(sum+1, -1);
    dp[0] = 1;
    dp[1] = 1;
    cout<<solve(sum)<<"\n";
    // print(dp);
}

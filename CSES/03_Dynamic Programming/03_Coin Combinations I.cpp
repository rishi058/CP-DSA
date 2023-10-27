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
#define inf INT_MAX - 1
#define Min LONG_LONG_MIN
 
typedef long double ld;
typedef vector<int> vi;
 
/*---------------------------------------->   MAGIC STARTS   <--------------------------------------------*/

/*
Consider a money system consisting of n coins. Each coin has a positive integer value. Your
task is to calculate the number of distinct ways you can produce a money sum c using the
available coins.
For example, if the coins are {2, 3, 5} and the desired sum is 9, there are 8 ways:
*/

int32_t main()
{
    RISHI
    int n, sum;
    cin>>n>>sum;
 
    vi coins(n);
    F(0,n,i){cin>>coins[i];}
    sort(all(coins));
 
    vi dp(sum+1,0);
    dp[0] = 1;
 
    for(int i=1; i<=sum; i++){
        for(int coin : coins){
            if(i-coin<0){break;}
            dp[i] = (dp[i]+dp[i-coin])%mod;
        }
    }
 
    cout<<dp[sum];
}

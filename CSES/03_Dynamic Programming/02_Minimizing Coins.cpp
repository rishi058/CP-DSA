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
task is to produce a sum of money c using the available coins in such a way that the number
of coins is minimal.
For example, if the coins are {1, 5, 7} and the desired sum is 11, an optimal solution is 5+
5 + 1 which requires 3 coins.

Input :- 
The first input line has two integers n and c: the number of coins and the desired sum of
money.
The second line has n distinct integers Cl, 02, ,cn: the value of each coin.

Output :-
Print one integer: the minimum number of coins. If it is not possible to produce the desired
sum, print —1.

Constraints :- 
• 1 < n < 100
• 1 <= x <= 10^6
• 1 <= Ci <= 10^6
*/

int32_t main()
{
    RISHI
    int n, sum;
    cin>>n>>sum;
 
    vi coins(n);
    F(0,n,i){cin>>coins[i];}
    sort(all(coins));
 
    vi dp(sum+1,inf);
    dp[0] = 0;
 
    for(int i=1; i<=sum; i++){
        for(int coin : coins){
            if(i-coin<0){break;}
            dp[i] = min(dp[i], dp[i-coin]+1);
        }
    }
 
    if(dp[sum]==inf){cout<<-1;}
    else{cout<<dp[sum];}
 
}

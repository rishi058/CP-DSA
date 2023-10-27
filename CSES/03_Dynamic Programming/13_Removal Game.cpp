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
There is a list of n numbers and two players who move alternately. On each move, a player
removes either the first or last number from the list, and their score increases by that
number. Both players try to maximize their scores.
What is the maximum possible score for the first player when both players play optimally?
*/

vector<vi> dp;
vi v;
 
int solve(int i, int j, bool turn){
    if(i>j){return 0;}
    if(i==j){
        if(turn){return 0;}
        return v[i];
    }
    if(dp[i][j]!=-1){return dp[i][j];}
 
    if(!turn){
        return dp[i][j] = max(solve(i+1, j, !turn) + v[i], solve(i,j-1,!turn)+v[j]);
    }
    
    return dp[i][j] = min(solve(i+1, j, !turn), solve(i,j-1,!turn));
}
 
int32_t main()
{
    RISHI
    int n; cin>>n;
    v.resize(n);
    F(0,n,i){cin>>v[i];}
    
    dp.resize(n, vector<int>(n,-1));
 
    solve(0, n-1, 0);
    // for(auto vec:dp){print(vec);}
    cout<<dp[0][n-1];
}

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
Your task is to count the number of ways you can fill an n x m grid using 1 x 2 and 2 x 1
tiles.
*/

int n, m;
int dp[1001][1<<11];
 
void generate(int mask, int i, int res, vector<int>& ans){
    if(i==n+1){
        ans.push_back(res);
        return;
    }
    
    if((mask & (1 << i)) != 0){
        generate(mask, i + 1, res, ans);
    }
    
    if(i != n){
        if((mask & (1 << i)) == 0 && (mask & (1 << (i+1))) == 0){
            generate(mask, i + 2, res, ans);   
        }
    }
   
    
    if((mask & (1 << i)) == 0){
        generate(mask, i + 1, res + (1 << i), ans);    
    }
}
 
 
int solve(int col, int mask){
    if(col == m){   // BASE CASE
        if(mask == 0){return 1;}
        return 0;
    }
 
    if(dp[col][mask] != -1){return dp[col][mask];}
 
    vector<int> ans;
    generate(mask, 1, 0, ans); // generate possible masks for col+1, based on mask
    
    int ways = 0;
    for(int next_mask : ans){
        ways = (ways + solve(col + 1, next_mask)) % mod;
    }
 
    return dp[col][mask] = ways;
}
 
int32_t main()
{
    RISHI
    cin>>n>>m;
    memset(dp, -1, sizeof dp);
    // dp.resize(m,vector<int>((1<<n), -1));
    // dp[i][j] = total ways to fill grid from i'th col, if set-bit of "j" represents used-up cell of i'th col.
    cout<<solve(0,0);
}
 

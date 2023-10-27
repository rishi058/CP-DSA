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
Consider an n x n grid whose squares may have traps. It is not allowed to move to a square
with a trap.
Your task is to calculate the number of paths from the upper-left square to the lower-right
square. You can only move right or down.
*/

int32_t main()
{
    RISHI
    int n; cin>>n;
 
    vector<string> grid;
    F(0,n,i){
        string str; cin>>str;
        grid.push_back(str);
    }
 
    vector<vi> dp(n, vector<int>(n,0));
    if(grid[0][0]!='*'){
        dp[0][0] = 1;
    }
 
    F(0,n,i){
        F(0,n,j){
            if(grid[i][j]=='*' || i+j==0){continue;}
            else if(i==0){dp[i][j]+=dp[i][j-1]; dp[i][j]%=mod;}
            else if(j==0){dp[i][j] += dp[i-1][j]; dp[i][j]%=mod;}
            else{
                if(grid[i-1][j]=='*' && grid[i][j-1]=='*'){continue;}
                else if(grid[i-1][j]=='*'){
                    dp[i][j] += dp[i][j-1];
                    dp[i][j]%=mod;
                }
                else if(grid[i][j-1]=='*'){
                    dp[i][j] += dp[i-1][j];
                    dp[i][j]%=mod;
                }
                else{
                    dp[i][j] += (dp[i-1][j]+dp[i][j-1]);
                    dp[i][j]%=mod;
                }
            }
        }
    }
 
    cout<<dp[n-1][n-1];
}

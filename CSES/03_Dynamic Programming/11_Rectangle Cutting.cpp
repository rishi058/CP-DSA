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
#define inf INT_MAX
#define Min LONG_LONG_MIN
 
typedef long double ld;
typedef vector<int> vi;
 
/*---------------------------------------->   MAGIC STARTS   <--------------------------------------------*/

/*
Given an a x b rectangle, your task is to cut it into squares. On each move you can select a
rectangle and cut it into two rectangles in such a way that all side lengths remain integers.
What is the minimum possible number of moves?
*/

vector<vector<int>> dp;
 
int solve(int a, int b){
    if(a>b){swap(a,b);}
    if(a==b){return 0;}
    if(a==1){return b-1;}
    if(b==1){return a-1;}
    if(dp[a][b]!=inf){return dp[a][b];}
 
    for(int i=1; i<a; i++){
        dp[a][b] = min(dp[a][b], solve(i,b)+solve(a-i,b)+1);
    }
    for(int i=1; i<b; i++){
        dp[a][b] = min(dp[a][b], solve(a, i)+solve(a,b-i)+1);
    }
 
    return dp[a][b];
}
 
int32_t main()
{
    RISHI
    int a, b;
    cin>>a>>b;
    int mx = max(a,b);
    dp.resize(mx+1, vector<int>(mx+1, inf));
    cout<<solve(a, b);
}

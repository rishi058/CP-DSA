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
You know that an array has n integers between 1 and m, and the absolute difference
between two adjacent values is at most 1.
Given a description of the array where some values may be unknown, your task is to count
the number of arrays that match the description.
*/

int32_t main()
{
    RISHI
 
    // T.C = O(N*M)
 
    int n, m;
    cin>>n>>m;
 
    vector<vi> dp(n, vector<int>(m+1, 0));  // dp[i][j] = count of possible arrays upto idx=i when m = j.
 
    vi v(n);
    F(0,n,i){cin>>v[i];}
 
    if(v[0]==0){
        fill(dp[0].begin(), dp[0].end(), 1);
    }
    else{
        dp[0][v[0]] = 1;
    }
 
    F(1,n,i){
 
        if(v[i]==0){
            F(1,m+1,j){
                dp[i][j] += dp[i - 1][j];
                if (j - 1 > 0) dp[i][j] += dp[i - 1][j - 1];
				if (j + 1 <= m) dp[i][j] += dp[i - 1][j + 1];
				dp[i][j] %= mod;
            }
        }
        else{
            dp[i][v[i]] += dp[i - 1][v[i]];
			if (v[i] - 1 > 0) dp[i][v[i]] += dp[i - 1][v[i] - 1];
			if (v[i] + 1 <= m) dp[i][v[i]] += dp[i - 1][v[i] + 1];
			dp[i][v[i]] %= mod;
        }
 
    }
 
    int ans = 0;
    F(1,m+1,i){
        ans += dp[n-1][i];
        ans %= mod;
    }
 
    cout<<ans;
 
}

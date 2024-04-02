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
 
//!------------------------ Practice like you've never won. Perform like you've never lost. ------------------------

/*
CSES - Comapany Queries I

A company has n employees, who form a tree hierarchy where each employee has a boss,
except for the general director.

Your task is to process q queries of the form: who is employee c's boss k levels higher up in
the hierarchy?
*/

vector<vector<int>> dp;
 
void pre(int n, vector<int>&par){
    dp.resize(n, vector<int>(20,-1));
 
    for(int i=0; i<n; i++){
        dp[i][0] = par[i];
    }
 
    for(int j=1; j<20; j++){
        for(int i=0; i<n; i++){
            if(dp[i][j - 1] == -1){
                dp[i][j] = -1;
            }
            else{
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
            }
        }
    }
    
}
 
int getKthAncestor(int node, int k) {
    for (int i = 0; i < 20; i++) {
        if ((k >> i) & 1) {
            node = dp[node][i];
            if (node == -1) return -1;
        }
    }
    return node;
}
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        int n, q;
        cin>>n>>q;
 
        vi par(n+1,0);
        par[0] = -1;
        par[1] = -1;
 
        F(2,n+1,i){
            int x; cin>>x;
            par[i] = x;
        }  
 
        pre(n+1, par);
 
        while(q--){
            int node, k;
            cin>>node>>k;
            int ans = getKthAncestor(node, k);
 
            if(ans==-1){cout<<"-1\n";}
            else{cout<<ans<<"\n";}
        }
 
    }
 
}

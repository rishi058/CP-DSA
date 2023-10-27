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
Given the structure of a company, your task is to calculate for each employee the number of their subordinates.
*/

void dfs(int node, vi &ans, vi adj[]){
    for(int child : adj[node]){
        dfs(child, ans, adj);
        ans[node] += ans[child] + 1;
    }
 
}
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        int n; cin>>n;
 
        vector<int> adj[n];
        F(1,n,i){
            int x; cin>>x;
            adj[--x].push_back(i);
        }        
 
        vi ans(n,0);
        dfs(0, ans, adj);
        print(ans);
    }
 
}

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
You are given a tree consisting of n nodes.

A matching is a set of edges where each node is an endpoint of at most one edge. What is the maximum number of edges in a matching?
*/

const int N = 2e5+1;
bool vis[N];
vector<int> adj[N];
 
void dfs(int node, int par, int &ans){   
    for(int child : adj[node]){
        if(child!=par){
            dfs(child, node, ans);
        }
    }
    if(!vis[par] && !vis[node] && par!=0){
        vis[par] = vis[node] = 1;
        ans++;
    }
}
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {   
        int n; cin>>n;
        
        F(1,n,i){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
 
        int ans = 0;
        dfs(1, 0, ans);
        cout<<ans<<"\n";
        
    }
 
}
 

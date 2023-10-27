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

The diameter of a tree is the maximum distance between two nodes. Your task is to determine the diameter of the tree.
*/

const int N = 2e5+1;
bool vis[N];
int depth[N];
vector<int> adj[N];
 
void dfs(int node){
    vis[node] = 1;
    for(int child : adj[node]){
        if(vis[child]){continue;}
        depth[child] = depth[node]+1;
        dfs(child);
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
 
        depth[1] = 0;
        dfs(1);
 
        int mx_node = 1, mx_depth = 0;
        F(1,n+1,i){
            if(depth[i]>mx_depth){
                mx_node = i;
                mx_depth = depth[i];
            }
        }
 
        memset(vis, 0, sizeof(vis));
        depth[mx_node] = 0;
        dfs(mx_node);
 
        int ans = 0;
        F(1,n+1,i){
            ans = max(ans, depth[i]);
        }
        cout<<ans<<"\n";
    }
 
}
 
 

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
Your task is to process q queries of the form: what is the distance between nodes a and b?

Input :-
The first input line contains two integers n and q: the number of nodes and queries. The
nodes are numbered 1, 2, ..., n.

Then there are n — 1 lines describing the edges. Each line contains two integers a and b:
there is an edge between nodes a and b.

Finally, there are q lines describing the queries. Each line contains two integer a and b: what
is the distance between nodes a and b?


if LCA(a,b) = a, ans = dist[a] - dist[b];
if LCA(a,b) = c, ans = (dist[c] - dist[b]) + (dist[c] - dist[a]_
*/
 
const int N = 2e5+2;
vector<int> adj[N];
int depth[N];
vector<vector<int>> dp;
 
void dfs(int node, int p_node, vi &par){
    depth[node] = depth[p_node] + 1;
    for(int child : adj[node]){
        if(child!=p_node){
            par[child] = node;
            dfs(child, node, par);
        }
    }
}
 
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
 
int findLCA(int u, int v) {
    // Ensure u is at a greater depth or swap them
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
 
    int k = depth[u] - depth[v];
    u = getKthAncestor(u, k);
 
    if(u == v){return u;}
 
    // Binary search to find the LCA
    for (int i = 19; i >= 0; --i) {
        if (dp[u][i] != dp[v][i]) {
            u = dp[u][i];
            v = dp[v][i];
        }
    }
 
    // The LCA is the parent of u or v
    return dp[u][0];
}
 
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        int n, q;
        cin>>n>>q;
 
        F(1,n,i){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }  
 
        vi par(n+1,0);
        par[0] = -1;
        par[1] = -1;
        dfs(1, 0, par);
        
        pre(n+1, par);
 
        // F(1,n+1,i){cout<<depth[i]<<" ";} cout<<"\n";
 
        while(q--){
            int node1, node2;
            cin>>node1>>node2;
 
            int lca = findLCA(node1, node2);
 
            if(lca==node1){
                cout<<(depth[node2] - depth[node1])<<"\n";
            }
            else if(lca==node2){
                cout<<(depth[node1] - depth[node2])<<"\n";
            }
            else{
                int dist = (depth[node1] - depth[lca]) + (depth[node2] - depth[lca]);
                cout<<dist<<"\n";
            }
        }
 
    }
 
}

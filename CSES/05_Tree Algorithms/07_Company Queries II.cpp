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
A company has n employees, who form a tree hierarchy where each employee has a boss,
except for the general director.
Your task is to process q queries of the form: who is the lowest common boss of employees
a and b in the hierarchy?


Finding LCA can be done in Log(n), with the help of binary lifting which is used
to find the k'th ancestor. 
*/
 
const int N = 2e5+2;
vector<int> adj[N];
int depth[N];
vector<vector<int>> dp;
 
void dfs(int node, int par){
    depth[node] = depth[par] + 1;
    for(int child : adj[node]){
        if(child!=par){
            dfs(child, node);
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
 
        vi par(n+1,0);
        par[0] = -1;
        par[1] = -1;
 
        F(2,n+1,i){
            int x; cin>>x;
            adj[x].push_back(i);
            par[i] = x;
        }  
 
        dfs(1, 0);
        pre(n+1, par);
 
        while(q--){
            int node1, node2;
            cin>>node1>>node2;
            
            int ans = findLCA(node1, node2);
            cout<<ans<<"\n";
        }
 
    }
 
}

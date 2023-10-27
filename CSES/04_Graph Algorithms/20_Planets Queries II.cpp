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
#define inf LONadjT_LONadjT_MAX
#define Min LONadjT_LONadjT_MIN
 
typedef long double ld;
typedef vector<int> vi;
 
/*---------------------------------------->   MAadjTIC STARTS   <--------------------------------------------*/
/*
 
Path queris ->
note :- out-degree of each node is exactly 1, i.e it's a pseudo-forest.
        1. Each adjTraph in the forest will contain exactly 1 cycle.
        2. every-node will lead to a cycle
 
Approach ->
1. if two nodes are from diffrent component return -1 (check using dsu)
 
2. if they are in same component, there will be 3 possiblites :-
   a.) both node is on cycle. [ans = dist[a]-dist[b]]
   b.) a is on tree and b is on cycle then ans = YES, vice-versa is NO. 
   c.) both is on tree then if LCA(a,b)==b, ans = YES else NO.
 
tree can be found by reversing the graph
--> LCA in LogN is a variation of Binary-lifting(get k'th ancestor) [note LCA is only possible on tree]
--> for this question this is enough - { if depth of a,b is "x","y" ["k" = 'a'-'b'], if k'th ancestor of a is b }
--> in tradional LCA algo, 1 more step is there, after the above step.
 
*/
 
const int N = 2e5+1, LogN = 20;
bool vis[N];  
int ds[N], comp[N];     // for DSU componets purpose
int dist[N];            // dist[a] = dist b/w cycle seed and a.
int cyc[N];             // cyc[a] = len_of_cycle, if 'a' is a part of cyc, o/w cyc[a] = 0;             
int dp[LogN][N];        // for pre-processing parent.
vector<int> cycleSeeds, adjT[N];
 
//***************************************************
// !Modified Disjoint Set 
 
int find(int u){
    if(ds[u] < 0)   return u;
    ds[u] = find(ds[u]);
    return ds[u];
}
 
bool merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v)  return false;
    if(ds[u] < ds[v])   swap(u, v);
    ds[v] += ds[u];
    ds[u] = v;
    return true;
}
 
//***************************************************
// !Binary Lifting
 
void pre(int n){
    for(int i = 1; i < LogN; i++)
        for(int j = 1; j <= n; j++)
            dp[i][j] = dp[i-1][dp[i-1][j]];
}
 
int getKthAncestor(int u, int k){
    int v = u;
    for(int i = LogN-1; i >= 0; i--)
        if(k&(1<<i))
            v = dp[i][v];
    return v;
}
 
//****************************************************
 
// !DFS for pre-processing depths
 
void dfs(int u, int compID){
    vis[u] = true;
    comp[u] = compID;
    for(int v : adjT[u]){
        if(!vis[v]){
            dist[v] = dist[u]+1;
            dfs(v, compID);
        } else cyc[u] = dist[u]+1;
        cyc[u] = max(cyc[u], cyc[v]);
    }
}
 
//*****************************************************
 
int query(int a, int b){
    if(a == b)  return 0;
 
    // Start and end are on different components
    if(comp[a] != comp[b])  return -1;
 
    // Start is on cycle
    if(cyc[a]){
        if(!cyc[b]) return -1;
        return (dist[a]-dist[b]+cyc[a]) % cyc[a];
    }
 
    // Start and end are on tree (must check if same tree)
    if(!cyc[b]){
        if(dist[a] <= dist[b]) {return -1;}
        int k = dist[a]-dist[b];
        return (getKthAncestor(a, k) == b) ? k : -1;
    }
 
    // Start is on tree and end is on cycle
    int root = a;
    for(int i = LogN-1; i >= 0; i--){
        int par = dp[i][root];
        if(!cyc[par])
            root = par;
    }
    root = dp[0][root];
 
    return (dist[a]-dist[root]) + query(root, b);
}
 
//***************************************************************
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        int n, q;
        cin>>n>>q;
 
        fill(ds+1, ds+N+1, -1);
 
        F(1,n+1,i){
            int x; cin>>x;
            dp[0][i] = x;
            adjT[x].push_back(i);
            if(!merge(x, i)){
                cycleSeeds.push_back(x);
            }
        }
 
        pre(n);
 
        int compID = 1;
        for(int seed : cycleSeeds)
            dfs(seed, compID++);
 
        while(q--){
            int a, b;
            cin>>a>>b;  
 
            int ans = query(a,b);
            cout<<ans<<"\n";
        }
    }
}

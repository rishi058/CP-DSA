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
A game has n rooms and m tunnels between them. Each room has a certain number of
coins. What is the maximum number of coins you can collect while moving through the
tunnels when you can freely choose your starting and ending room?
*/

/*
we split the graph into SCCs. We then treat each component as a node. 
So then, If the coin collector enters a component, he can collect all the coins in it.
the resulting graph is a DAG, we can use DP to find the maximum coins that can be collected
*/
 
const int N = 1e5+5;
vector<int> adj[N], adjT[N], SCC[N];
int dp[N], scc_cost[N], scc[N];
bool vis[N];
vector<int> ord, comp;
 
void dfs1(int u){     // kosaraju
    vis[u] = 1;
    for(int v : adj[u]){if(!vis[v]){dfs1(v);}}
    ord.push_back(u);
}
 
void dfs2(int u){   // kosaraju_rev
    vis[u] = 1;
    comp.push_back(u);
    for(int v : adjT[u]){if(!vis[v]){dfs2(v);}}
}
 
void dfs3(int u){    // dp-dfs for DAG
    vis[u] = 1;
    dp[u] = scc_cost[u];
    for(int v : SCC[u]){
        if(!vis[v]){dfs3(v);}
        dp[u] = max(dp[u], dp[v]+scc_cost[u]);
    }
}
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        int n, m;
        cin>>n>>m;
 
        vi cost(n+1);
        F(0,n,i){cin>>cost[i+1];}
 
        F(0,m,i){  // previous mistake
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adjT[v].push_back(u);
        }
 
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                dfs1(i);
            }
        }
 
        reverse(all(ord));
        memset(vis, 0, sizeof(vis));
 
        int k = 1;
        for(int x : ord){
            if(!vis[x]){
                dfs2(x);
                for(int x : comp){
                    scc_cost[k] += cost[x];
                    scc[x] = k;
                }
                k++;
                comp.clear();
            }
        }
 
        for(int i=1; i<=n; i++){     // creating new DAG after compressing scc.
            for(int v : adj[i]){
                if(scc[v]!=scc[i]){
                    SCC[scc[i]].push_back(scc[v]);
                }
            }
        }
 
        memset(vis, 0, sizeof(vis));
 
        for(int i=1; i<k; i++){
            if(!vis[i]){
                dfs3(i);
            }
        }
 
        int ans = *max_element(dp, dp+k+1);
        cout<<ans<<"\n";
 
    }
 
}

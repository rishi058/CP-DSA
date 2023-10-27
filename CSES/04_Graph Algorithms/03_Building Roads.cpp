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
Byteland has n cities, and m roads between them. The goal is to construct new roads so that
there is a route between any two cities.
Your task is to find out the minimum number of roads required, and also determine which
roads should be built.
*/

void dfs(int node, vector<int>adj[], vector<bool>&vis){
    vis[node] = 1;
 
    for(int child : adj[node]){
        if(!vis[child]){
            dfs(child, adj, vis);
        }
    }
}
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
 
        vector<int> adj[n];
        F(0,m,i){
            int u,v;
            cin>>u>>v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> vis(n,0);
 
        int ans = 0;
        vector<int> res;
 
        dfs(0, adj, vis);
 
        for(int i=1; i<n; i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                ans++;
                res.push_back(i+1);
            }
        }
 
        cout<<ans<<"\n";
        for(int x : res){
            cout<<"1 "<<x<<"\n";
        }
    }
 
}

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
There are n pupils in Uolevi's class, and m friendships between them. Your task is to divide
the pupils into two teams in such a way that no two pupils in a team are friends. You can
freely choose the sizes of the teams.
*/

bool dfs(int node, int color, vector<int> adj[], vector<int> &vis){
    vis[node] = color;
    for(int child : adj[node]){
        if(vis[child]==-1){
            if(dfs(child, !color, adj, vis)==false){return false;}
        }
        else{
            if(vis[child]==vis[node]){
                return false;
            }
        }
    }
    return true;
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
 
        vector<int> vis(n,-1);
 
        bool ans = true;
        for(int i=0; i<n; i++){
            if(vis[i]==-1){
                ans =  dfs(i, 1, adj, vis);
                if(ans==false){break;}
            }
        }
 
        if(ans){
            for(int x : vis){cout<<x+1<<" ";}
        }
        else{
            cout<<"IMPOSSIBLE\n";
        }
 
    }
 
}
 

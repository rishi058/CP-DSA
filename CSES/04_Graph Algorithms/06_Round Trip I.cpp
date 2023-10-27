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
Byteland has n cities and m roads between them. Your task is to design a round trip that
begins in a city, goes through two or more other cities, and finally returns to the starting
city. Every intermediate city on the route has to be distinct.
*/

int ans;
int len;
vector<int> vis;
vector<int> par;
 
bool dfs(int node, int parent, vector<int>adj[]){
    vis[node]=vis[parent]+1;
    par[node] = parent;
    bool isloopexist = false;
    for(int child : adj[node]){
        if(vis[child] && child==parent){continue;}
        if(vis[child]) {ans=child; len=vis[child]-vis[node]+1; return true;}
        isloopexist |= dfs(child, node, adj);
    }
    return isloopexist;
}
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
 
        vector<int> adj[n+1];
        F(0,m,i){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
 
        vis.resize(n+1,0);
        par.resize(n+1,0);
        bool ok = 0;
        for(int i=1; i<n; i++){
            if(!vis[i]){
                ok = dfs(i, 0, adj);
                if(ok){break;}
            }
        }
 
        // print(par);
        // cout<<ans<<" "<<len<<"\n";
 
        if(ok){
            vector<int> res;
            F(0,len,i){
                res.push_back(ans);
                ans = par[ans];
            }
            res.push_back(res[0]);
            cout<<res.size()<<"\n";
            print(res);
        }
        else{
            cout<<"IMPOSSIBLE\n";
        }
 
    }
 
}

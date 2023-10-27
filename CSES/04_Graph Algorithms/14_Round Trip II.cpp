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
Byteland has n cities and m flight connections. Your task is to design a round trip that
begins in a city, goes through one or more other cities, and finally returns to the starting
city. Every intermediate city on the route has to be distinct.
*/

int temp;
vector<int> par;
 
bool dfs(int node, vector<int> graph[], vector<bool> &vis, vector<bool> &pathVis){
    vis[node] = 1;
    pathVis[node] = 1;
    
    for(int child : graph[node]){
        par[child] = node;
        if(!vis[child]){
            if(dfs(child, graph, vis, pathVis)==true){return true;}
        }
        else if(pathVis[child]){temp=child; return true;}
    }
 
    pathVis[node] = 0;
    return false;
}
 
 
bool isCyclic(int n, vector<int> graph[]){
    vector<bool> vis(n, false);
    vector<bool> pathVis(n, false);
 
    for(int i=0; i<n; i++){
        if(!vis[i]){
            if(dfs(i,graph,vis,pathVis)==true){return true;}
        }
    }
    return false;
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
        }
 
        par.resize(n,-1);
        bool ok = isCyclic(n, adj);
 
        if(ok){
            vector<int> ans;
            while(1){
                ans.push_back(temp+1);
                temp = par[temp];
                if(ans.size()>1 && ans[0]==ans.back()){break;}
            }
            reverse(all(ans));
            cout<<ans.size()<<"\n";
            print(ans);
        }
        else{
            cout<<"IMPOSSIBLE\n";
        }
 
    }
 
}

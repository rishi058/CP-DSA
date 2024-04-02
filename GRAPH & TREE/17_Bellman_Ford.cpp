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
CSES : Cycle Finding.

You are given a directed graph, and your task is to find out if it contains a negative cycle,
and also give an example of such a cycle.
*/

struct Edge{
    int u, v, wt;
    Edge(int a, int b, int c){
        u = a, v = b, wt = c;
    }
};
 
vector<int> generate(int node, vector<int>&par){
    vector<int> path = {node+1};
    int start = par[node];
    while(start!=node){
        path.push_back(start+1);
        start = par[start];
    }
    path.push_back(node+1);
    reverse(all(path));
    return path;
}
 
void dfs(int node, vector<bool>&vis, vector<int>adj[]){
    vis[node] = 1;
    for(int child : adj[node]){
        if(!vis[child]){
            dfs(child, vis, adj);
        }
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
        
        vector<Edge> Edges;
        vector<bool> vis(n,0);
        vector<int> adj[n];
 
        F(0,m,i){
            int u,v,wt;
            cin>>u>>v>>wt;
            u--; v--;
 
            adj[u].push_back(v);
            Edge temp(u,v,wt);
            Edges.push_back(temp);
        }        
 
 
        vector<int> dist(n, inf);
        vector<int> par(n, -1);
        
        for(int i=0; i<n; i++){
            if(!vis[i]){dist[i]=0; dfs(i, vis, adj);}
        }
 
        for(int i=0; i<n-1; i++){
            for(int j=0; j<m; j++){
                int u = Edges[j].u;
                int v = Edges[j].v;
                int wt = Edges[j].wt;
                if (dist[u]!=inf && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                    par[v] = u;
                }
            }
        }   
 
        vector<int> dist2 = dist;
        int node = -1;
 
        for(int j=0; j<m; j++){  // running relaxation nth time.
            int u = Edges[j].u;
            int v = Edges[j].v;
            int wt = Edges[j].wt;
            if (dist2[u]!=inf && dist2[u] + wt < dist2[v]){
                dist2[v] = dist2[u] + wt;
                par[v] = u;
                node = v;
            }
        } 
 
        if(node!=-1){
            F(0,n,i){node=par[node];}
            cout<<"YES\n";
            vi ans = generate(node, par);
            print(ans);
        }
        else{
            cout<<"NO\n";
        }
       
    }
 
}

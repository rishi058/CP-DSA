#include <bits/stdc++.h>
using namespace std;

#define int long long
#define tuple array<int, 3>
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
https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/

EXAMPLE INPUT : 
4 4
0 1
1 2
2 3
3 3
*/

bool dfs_isCyclic(int node, vector<int> graph[], vector<bool> &vis, vector<bool> &pathVis){
    vis[node] = 1;
    pathVis[node] = 1;
    for(int child : graph[node]){
        if(!vis[child]){
            if(dfs_isCyclic(child, graph, vis, pathVis)){return true;}
        }
        else if(pathVis[child]){return true;}
    }

    pathVis[node] = 0;
    return false;
}

int32_t main()
{
    RISHI
    int T = 1;
    // cin>>T;
    while(T--)
    {
        int n, m;
        cin>>n>>m;

        vector<int> adj[n];        // O indexed
        F(0,m,i){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
        }

        vector<bool> vis(n,0), pathVis(n,0);

        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(dfs_isCyclic(i, adj, vis, pathVis)){
                    cout<<i<<"\n";
                    break;
                }
            }
        }
        
    }

}



//      ██╗  █████╗  ██╗    ██████╗ ██╗  ██╗ ██████╗  ███████╗ ███████╗   ██████╗   █████╗  ███╗   ███╗
//      ██║ ██╔══██╗ ██║   ██╔════╝ ██║  ██║ ██╔══██╗ ██╔════╝ ██╔════╝   ██╔══██╗ ██╔══██╗ ████╗ ████║
//      ██║ ███████║ ██║   ╚█████╗  ███████║ ██████╔╝ █████╗   █████╗     ██████╔╝ ███████║ ██╔████╔██║
// ██╗  ██║ ██╔══██║ ██║    ╚═══██╗ ██╔══██║ ██╔══██╗ ██╔══╝   ██╔══╝     ██╔══██╗ ██╔══██║ ██║╚██╔╝██║
// ╚█████╔╝ ██║  ██║ ██║   ██████╔╝ ██║  ██║ ██║  ██║ ███████╗ ███████╗   ██║  ██║ ██║  ██║ ██║ ╚═╝ ██║
//  ╚════╝  ╚═╝  ╚═╝ ╚═╝   ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚══════╝ ╚══════╝   ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝     ╚═╝
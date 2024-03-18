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

If Graph is cyclic then its topological sort isn't possible i.e (topo.size()!=n)

https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

EXAMPLE INPUT : 
4 4
0 1
1 2
2 3
3 3

*/

vector<int> KahnAlgo(int n, vector<int> adj[]){  // (n=no. of vertices, adjacency mat)
    
    int indegree[n] = {0};
    for(int i=0; i<n; i++){
        for(int x : adj[i]){
            indegree[x]++;
        }
    }

    queue<int> q;
    for(int i=0; i<n; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(int x : adj[node]){
            indegree[x]--;
            if(indegree[x]==0){q.push(x);}
        }

    }

    return topo;
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
                vector<int> topo = KahnAlgo(i, adj);
                if(topo.size()!=n){
                    cout<<"Cycle Detected";
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
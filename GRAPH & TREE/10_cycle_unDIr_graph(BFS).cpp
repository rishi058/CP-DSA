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
https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

EXAMPLE :-

4 2
2 1
2 3
------------->

   | 0 :        |
   | 1 : 2      |
   | 2 : 1 3    |
   | 3 : 2      |


*/

bool isCyclic(int src, vector<bool>&vis, vector<int>adj[]){

    queue<pair<int,int>> q;
    q.push({src, -1});
    vis[src] = 1;

    while(!q.empty()){
        int node = q.front().first;
        int par = q.front().second;      //!  IMP
        q.pop();

        for(int child : adj[node]){
            if(!vis[child]){
                vis[child] = 1;
                q.push({child, node});
            }
            else if(child!=par){return 1;}   //!  IMP
        }   
    }

    return 0;
}
    
bool isCycle(int V, vector<int> adj[]){
    vector<bool> vis(V, 0);
    
    for(int i=0; i<V; i++){
        if(!vis[i]){
            if(isCyclic(i, vis, adj)){
                return 1;
            }
        }
    }
    
    return 0;
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
            adj[v].push_back(u);
        }

        cout<<isCycle(n, adj)<<"\n";
        
    }

}



//      ██╗  █████╗  ██╗    ██████╗ ██╗  ██╗ ██████╗  ███████╗ ███████╗   ██████╗   █████╗  ███╗   ███╗
//      ██║ ██╔══██╗ ██║   ██╔════╝ ██║  ██║ ██╔══██╗ ██╔════╝ ██╔════╝   ██╔══██╗ ██╔══██╗ ████╗ ████║
//      ██║ ███████║ ██║   ╚█████╗  ███████║ ██████╔╝ █████╗   █████╗     ██████╔╝ ███████║ ██╔████╔██║
// ██╗  ██║ ██╔══██║ ██║    ╚═══██╗ ██╔══██║ ██╔══██╗ ██╔══╝   ██╔══╝     ██╔══██╗ ██╔══██║ ██║╚██╔╝██║
// ╚█████╔╝ ██║  ██║ ██║   ██████╔╝ ██║  ██║ ██║  ██║ ███████╗ ███████╗   ██║  ██║ ██║  ██║ ██║ ╚═╝ ██║
//  ╚════╝  ╚═╝  ╚═╝ ╚═╝   ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚══════╝ ╚══════╝   ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝     ╚═╝
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
 
//!------------------------ Practice like you've never won. Perform like you've never lost. ------------------------

/*
You are given a tree consisting of n nodes.
Your task is to determine for each node the maximum distance to another node.

Input :-

The first input line contains an integer n: the number of nodes. The nodes are numbered
1,2,...,n.

Then there are n — 1 lines describing the edges. Each line contains two integers a and b:
there is an edge between nodes a and b.
*/

const int N = 2e5+1;
bool vis[N];
vector<int> adj[N];
 
void dfs(int node, vector<int>&depth){
    vis[node] = 1;
    for(int child : adj[node]){
        if(vis[child]){continue;}
        depth[child] = depth[node]+1;  // modification
        dfs(child, depth);
    }
}
 
int findMax(vector<int>&depth){
    int mx = *max_element(all(depth));
    F(1,depth.size(),i){
        if(depth[i]==mx){return i;}
    }
    return 0;
}
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {   
        int n; cin>>n;
        
        F(1,n,i){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
 
        vector<int> depth0(n+1, 0);  // depth from root i.e 1
        vector<int> depth1(n+1, 0);  // depth from diameter end1
        vector<int> depth2(n+1, 0);  // depth from diameter end2
 
        depth0[1] = 0;
        dfs(1, depth0);
        // print(depth0);
 
        memset(vis, 0, sizeof(vis));
        int end1 = findMax(depth0);
        depth1[end1] = 0;
        dfs(end1, depth1);
        // print(depth1);
 
 
        memset(vis, 0, sizeof(vis));
        int end2 = findMax(depth1);
        depth2[end2] = 0;
        dfs(end2, depth2);
        // print(depth2);
 
        F(1,n+1,i){
            cout<<max(depth1[i], depth2[i])<<" ";
        }
    }
 
}
 

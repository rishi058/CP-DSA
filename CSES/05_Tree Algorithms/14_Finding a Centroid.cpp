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
Given a tree of n nodes, your task is to find a centroid, i.e., a node such that when it is
appointed the root of the tree, each subtree has at most [n/2] nodes.


Find Centroid of a tree,
i.e A vertex such that when it becomes root, each subtree has atmost [n/2] nodes.
 
Approach ->
1. Calculate Subtree Size of each nodes via dfs(using 1 as root) [Note -> Subtree size of root_note will be max]
 
2. Run another dfs, start moving from root node to its child with max-subtree-size until the subtree_size>[n/2].
 
3. The final node is our ans.
*/
 
const int N = 2e5+1;
vector<int> adj[N];
int subtreeSize[N];
int n;
 
void dfs1(int node, int par){
    int nd_ct = 1;
    for(int child : adj[node]){
        if(child!=par){
            dfs1(child, node);
            nd_ct += subtreeSize[child];
        }
    }
    subtreeSize[node] = nd_ct;
}
 
int dfs2(int node, int par){
    for(int child : adj[node]){
        if(child!=par){
            int ok = subtreeSize[child] * 2;
            if(ok>n){
                return dfs2(child, node);
            }
        }
    }
    return node;
}
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        cin>>n;
        F(1,n,i){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        dfs1(1,0);
        int ans = dfs2(1,0);
        cout<<ans<<"\n";
    }
 
}
 

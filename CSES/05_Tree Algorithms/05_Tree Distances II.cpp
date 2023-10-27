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
Your task is to determine for each node the sum of the distances from the node to all other
nodes.

Input :-
The first input line contains an integer n: the number of nodes. The nodes are numbered
1,2,...,n.
Then there are n — 1 lines describing the edges. Each line contains two integers a and b:
there is an edge between nodes a and b.

DP on trees. [https://www.youtube.com/watch?v=ghGbPzwk0L0]
 
SubtreeAns[u]: sum of distances from u to each node in subtree rooted at u.
              { (for all child of u) SubtreeAns[u] += [ SubtreeAns[child] + nodes_ct[child] ] } 
              { Subtree[leaf] = 0, nodes_ct[i] = count of nodes in subtree rooted @ i }
 
Ans[u] = subtreeAns[u] + (semi-ans[par[u]] + (N - nodes_ct[u]) )  [semi-ans[par[u]] = ans[par[u]] when u isn't taken]
*/
 
const int N = 2e5+2;
int nodes_ct[N], subtreeAns[N], ans[N];
vector<int> adj[N];
 
void pre_dfs(int src, int par){       // pre-processing to fill nodes_ct and subtreeAns
    int numOfNodes = 1, ansForSubtree = 0;
    for(int child : adj[src]){
        if(child != par){
            pre_dfs(child, src);
            numOfNodes += nodes_ct[child];
            ansForSubtree += nodes_ct[child] + subtreeAns[child];
        }
    }
    nodes_ct[src] = numOfNodes;
    subtreeAns[src] = ansForSubtree;
}
 
 
 
void solve_dfs(int src, int par, int par_ans, int& totalNodes){            // dfs to find ans.
 
    ans[src] = subtreeAns[src] + (par_ans + (totalNodes - nodes_ct[src]));
 
    for(int child : adj[src]){
        if(child != par){
            int p_ans = ans[src] - (subtreeAns[child] + nodes_ct[child]);
            solve_dfs(child, src, p_ans, totalNodes);
        }
    }
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
 
        pre_dfs(1, 0);
        solve_dfs(1, 0, 0, n);
 
        F(1,n+1,i){
            cout<<ans[i]<<" ";
        }
    }
 
}

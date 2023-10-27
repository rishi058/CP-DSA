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
You are given a rooted tree consisting of n nodes. The nodes are numbered 1, 2, ...,n, and
node 1 is the root. Each node has a color.
Your task is to determine for each node the number of distinct colors in the subtree of the
node.
*/

// Can be solved using -> small-to-large-merging / BIT / Mo's algo.
 
const int N = 2e5+1;
vector<int> adj[N];
int value[N], ans[N];
 
void dfs(int node, vector<bool>&vis, vector<set<int>>&track){
    vis[node] = 1;
    track[node].insert(value[node]);
    for(int child : adj[node]){
        if(!vis[child]){
            dfs(child, vis, track);
 
            if(track[node].size() < track[child].size()){       // Small to Large Merging.
				swap(track[node], track[child]);
			}
		    for(int x : track[child]){track[node].insert(x);}
        }
    }
    ans[node] = track[node].size();
}
 
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        int n; cin>>n;
        F(1,n+1,i){cin>>value[i];}
 
        F(1,n,i){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<set<int>> track(n+1);
        vector<bool> vis(n+1, 0);
        dfs(1, vis, track);
 
        F(1,n+1,i){cout<<ans[i]<<" ";}
 
    }
 
}
 

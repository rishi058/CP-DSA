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
You are playing a game consisting of n planets. Each planet has a teleporter to another
planet (or the planet itself).
You start on a planet and then travel through teleporters until you reach a planet that you
have already visited before.
Your task is to calculate for each planet the number of teleportations there would be if you
started on that planet.
*/

/*
 
Path Cycle ->
note :- out-degree of each node is exactly 1, i.e it's a pseudo-forest.
        1. Each Graph in the forest will contain exactly 1 cycle.
        2. every-node will lead to a cycle
 
Approach ->
1. set dist[i] = len_of_cycle, {i = nodes which belongs to cycle}.
2. Create a rev graph. to iterate from first nodes connected to cycle to leave nodes.
2. set dist[i] = depth of tree [if depth of root = len_of_cycle+1]
 
*/
 
const int N = 2e5+1;
vector<int> dist;
vector<bool> isCyc;
vector<int> adj[N];      // reverse graph
 
// dfs for finding cycle and set dist[i] = len.
void dfs(int node, int ct, vector<int> &vis, vi& tel, vi &track){
    if(node==tel[node]){dist[node]=1; isCyc[node]=1; return;}
 
    vis[node] = ct;
    track.push_back(node);
    node = tel[node];
 
 
    if(vis[node]>0){
        reverse(all(track));
        while(track.back()!=node){
            track.pop_back();
            if(track.empty()){return;}
        }
        for(int x : track){dist[x]=ct-vis[node]+1; isCyc[x]=1;}
    }
 
    else{
        dfs(node, ct+1, vis, tel, track);
    }
 
}
 
// dfs_for_tree
void dfs2(int node, int par){
    dist[node] = dist[par] + 1;
    for(int child : adj[node]){
        if(dist[child]==0){
            dfs2(child, node);
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
 
        dist.resize(n,0);
        isCyc.resize(n,0);
 
        vi tel(n,0);    // teleporters..
 
        F(0,n,i){
            cin>>tel[i];
            tel[i]--;
            adj[tel[i]].push_back(i);
        }
 
        vector<int> vis(n,0);
 
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                vi temp;
                dfs(i, 1, vis, tel, temp);
                // print(dist);
            }
        }
 
 
        for(int i=0; i<n; i++){
            if(isCyc[i]==1){
                for(int child : adj[i]){
                    if(!isCyc[child]){    // edge_case
                        dfs2(child, i);
                    }
                }
            }
        }
 
        print(dist);
    }
 
}

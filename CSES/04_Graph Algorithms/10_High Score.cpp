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
You play a game consisting of n rooms and m tunnels. Your initial score is O, and each tunnel
increases your score by c where c may be both positive or negative. You may go through a
tunnel several times.
Your task is to walk from room 1 to room n. What is the maximum score you can get?
*/

/*
Run the Bellman-Ford Algorithm for the nth iteration and mark 
the nodes whose distance is changed.
Now reverse the adjacency list and run a DFS from node 'n'. 
If at least one of the nodes marked is visible from n, then the answer is -1,
else the answer is the maximum distance from 1 to n.
*/
 
struct Edge{
    int u, v, wt;
    Edge(int a, int b, int c){
        u = a, v = b, wt = c;
    }
};
 
bool dfs(int node, map<int,bool>&mp, vector<bool>&vis, vector<int> adj[]){
    vis[node] = 1;
    if(mp.count(node)){return 1;}
    for(int child : adj[node]){
        if(!vis[child]){
            if(dfs(child, mp, vis, adj)){return 1;}
        }
    }
    return 0;
}
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        int n, m;
        cin>>n>>m;
 
        vector<int> rev_adj[n];
        vector<Edge> Edges;
 
        F(0,m,i){
            int u,v,wt;
            cin>>u>>v>>wt;
            u--; v--;
 
            rev_adj[v].push_back(u);
 
            Edge temp(u,v,-wt);
            Edges.push_back(temp);
        }        
 
 
        vector<int> dist(n, inf);
        dist[0] = 0;
 
        for(int i=0; i<n-1; i++){
            for(int j=0; j<m; j++){
                int u = Edges[j].u;
                int v = Edges[j].v;
                int wt = Edges[j].wt;
                if (dist[u] != inf && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }   
 
        vector<int> dist2 = dist;
        map<int,bool> effected_nodes;

        cout<<effected_nodes.size()<<" ";
 
        for(int j=0; j<m; j++){  // running relaxation nth time.
            int u = Edges[j].u;
            int v = Edges[j].v;
            int wt = Edges[j].wt;
            if (dist2[u] != inf && dist2[u] + wt < dist2[v]){
                dist2[v] = dist2[u] + wt;
            }
        } 
 
        for(int i=0; i<n; i++){
            if(dist[i]!=dist2[i]){
                effected_nodes[i]=1;
            }
        }
 
        vector<bool> vis(n,0);
        bool ok = dfs(n-1, effected_nodes, vis, rev_adj);
        
        if(ok){cout<<"-1\n";}
        else{
            cout<<-dist[n-1]<<"\n";
        }   
    }
 
}
 

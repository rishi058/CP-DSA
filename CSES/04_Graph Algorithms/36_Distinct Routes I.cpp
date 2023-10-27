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
DISTINCT PATHS :-
A game consists of n rooms and m teleporters. At the beginning of each day, you start in
room 1 and you have to reach room n.
ou can use each teleporter at most once during the game. How many days can you play if
ou choose your routes optimally?

Approach :-
It's a transformation question from finding maximum flow,
We have to Find all Edge-disjoint paths, refer(cses book)
Count of Edge-Disjoint Paths = Maximum Flow of Graph when wt of each edge is 1.
 
Note (refer stack-overflow) :-
1. The augmenting paths used by Ford--Fulkerson are not immediately useful.
2. greedily extract paths after the completion of max-flow, from resudual graph.
 
There is also a similar question of Finding all Node-Disjoint Paths[cses book]
 
*/
 
const int V = 501;
bool vis[2*V + 2];
int Graph[V][V], rGraph[V][V];  // Main Graph, Residual Graph...
 
vector<pair<int,int>> adj[V];
vector<int> path;
 
void dfs(int u, int t){
    path.push_back(u+1);
    if(u == t)  return;
    for(auto [v, id] : adj[u]){
        if(rGraph[u][v] == 0 && !vis[id]){
            vis[id] = 1;   // marking the edge visited
            dfs(v,t);
            return;
        }
    }
}
 
bool bfs(int Graph[V][V], int s, int t, int parent[]) {
  bool visited[V];
  memset(visited, 0, sizeof(visited));
 
  queue<int> q;
  q.push(s);
  visited[s] = true;
  parent[s] = -1;
 
  while (!q.empty()) {
    int u = q.front();
    q.pop();
 
    for (int v = 0; v < V; v++) {
      if (visited[v] == false && rGraph[u][v] > 0) {
        q.push(v);
        parent[v] = u;
        visited[v] = true;
      }
    }
  }
 
  return (visited[t] == true);
}
 
// Applying fordfulkerson algorithm   (copied from programiz.com)
int fordFulkerson(int graph[V][V], int s, int t) {
  int u, v;
 
  for (u = 0; u < V; u++)
    for (v = 0; v < V; v++)
      rGraph[u][v] = graph[u][v];
 
  int parent[V];
  int max_flow = 0;
 
  // Updating the residual values of edges
  while (bfs(rGraph, s, t, parent)) {
    int path_flow = inf;
    for (v = t; v != s; v = parent[v]) {
      u = parent[v];
      path_flow = min(path_flow, rGraph[u][v]);
    }
 
    for (v = t; v != s; v = parent[v]) {
      u = parent[v];
      rGraph[u][v] -= path_flow;
      rGraph[v][u] += path_flow;
    }
    
    max_flow += path_flow;
  }
 
  return max_flow;
}
 
 
int32_t main()
{
	RISHI
	int T = 1;
	while(T--)
	{
		int n, m;
		cin>>n>>m;
 
		F(0,m,i){
			int u, v;
			cin>>u>>v;
			u--; v--;
            adj[u].push_back({v,i});
			Graph[u][v]++;
		}
 
		int mx = fordFulkerson(Graph, 0, n-1);
        cout<<mx<<"\n";
    
        while(mx--){
          path.clear();
          dfs(0, n-1);
          cout<<path.size()<<"\n";
          print(path);
        }
 
	}
 
}

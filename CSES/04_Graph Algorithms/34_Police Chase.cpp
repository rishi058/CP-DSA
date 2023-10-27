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
Police Chase :-
Kaaleppi has just robbed a bank and is now heading to the harbor. However, the police
wants to stop him by closing some streets of the city.
What is the minimum number of streets that should be closed so that there is no route
between the bank and the harbor?

Approach :-
In this problem we have to find minimum-cut of the graph->
below is the solution using ford-fulkerson algo.
 
refer https://cses.fi/book/book.pdf#page=195
*/
 
const int V = 501;
int Graph[V][V];
vector<pair<int,int>> res_edges;
 
bool bfs(int rGraph[V][V], int s, int t, int parent[]) {
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
 
void dfs(int rGraph[V][V], int s, bool visited[]){
    visited[s] = true;
    for (int i = 0; i < V; i++)
       if (rGraph[s][i] && !visited[i])
           dfs(rGraph, i, visited);
}
 
// Applying fordfulkerson algorithm   (copied from programiz.com)
int fordFulkerson(int graph[V][V], int s, int t) {
    int u, v;
    
    int rGraph[V][V];
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
    
      // Adding the path flows
      max_flow += path_flow;
    }
    
    // taken from gfg
    bool vis[V];
    memset(vis, false, sizeof(vis));
    dfs(rGraph, s, vis);
 
    for (int i = 0; i < V; i++)
      for (int j = 0; j < V; j++)
        if (vis[i] && !vis[j] && graph[i][j])
            res_edges.push_back({i,j});
 
 
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
			Graph[u][v]++;
			Graph[v][u]++;     // diffrent from prev, max-flow solution
		}
 
		int ans = fordFulkerson(Graph, 0, n-1);
 
		cout<<ans<<"\n";
        for(auto [u,v] : res_edges){
            cout<<u+1<<" "<<v+1<<"\n";
        }
		
	}
 
}

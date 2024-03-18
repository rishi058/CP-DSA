#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
#define F(a,b,i) for (int i = a; i < b; i++)
#define RISHI ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------
// https://leetcode.com/problems/longest-cycle-in-a-graph

map<int,vector<int>> graph;
int vis[100005];
set<int> cycle;

void dfs(int vertex, int ct){
    vis[vertex]=ct;
    for(int child : graph[vertex]){
      if(vis[child]>0){
        if(vis[child]==ct){cycle.insert(child);}
        return;
      }
      dfs(child, ct);
    }
}

void dfs2(int vertex, int &ct){
    vis[vertex]=true;
    ct++;
    for(int child : graph[vertex]){
      if(vis[child]) {return;}
      dfs2(child, ct);
    }
}

int longestCycle(vector<int>& edges) {
  int n = edges.size();
  for(int i=0; i<n; i++){
    int x = edges[i];
    if(x<0){continue;}
    graph[i].push_back(x);
  }

  int ct=1;
  for(int i=0; i<n; i++){
    if(vis[i]>0) {continue;}
    dfs(i, ct);
    ct++;
  }

  memset(vis, false, sizeof(vis));
  int ans=-1;
  for(int x : cycle){
    int temp=0;
    dfs2(x, temp);
    ans = max(ans,temp);
  }

  return ans;
}


int32_t main()
{
  RISHI
  vi v = {3,3,4,2,3} ;
  // i is connected to v[i] {Directed} 
  cout<<longestCycle(v);

}



// ███████╗██╗███╗   ██╗██╗███████╗██╗  ██╗    ██╗    ██╗██╗  ██╗ █████╗ ████████╗    ██╗   ██╗ ██████╗ ██╗   ██╗    ███████╗████████╗ █████╗ ██████╗ ████████╗    ██╗
// ██╔════╝██║████╗  ██║██║██╔════╝██║  ██║    ██║    ██║██║  ██║██╔══██╗╚══██╔══╝    ╚██╗ ██╔╝██╔═══██╗██║   ██║    ██╔════╝╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝    ██║
// █████╗  ██║██╔██╗ ██║██║███████╗███████║    ██║ █╗ ██║███████║███████║   ██║        ╚████╔╝ ██║   ██║██║   ██║    ███████╗   ██║   ███████║██████╔╝   ██║       ██║
// ██╔══╝  ██║██║╚██╗██║██║╚════██║██╔══██║    ██║███╗██║██╔══██║██╔══██║   ██║         ╚██╔╝  ██║   ██║██║   ██║    ╚════██║   ██║   ██╔══██║██╔══██╗   ██║       ╚═╝
// ██║     ██║██║ ╚████║██║███████║██║  ██║    ╚███╔███╔╝██║  ██║██║  ██║   ██║          ██║   ╚██████╔╝╚██████╔╝    ███████║   ██║   ██║  ██║██║  ██║   ██║       ██╗
// ╚═╝     ╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝     ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝          ╚═╝    ╚═════╝  ╚═════╝     ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝       ╚═╝
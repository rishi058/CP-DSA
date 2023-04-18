#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

// GOOGLE KICKSTART - ROUND H - Q.3

void dfs(map<int,vi> &graph, int vertex, vi &vis, vi &dp){
  vis[vertex] = 1;
  for(int child : graph[vertex]){
    if(vis[child]==0){
      dfs(graph,child,vis,dp);
    }
    dp[vertex] += dp[child];
  }
  ++dp[vertex];
}

int32_t main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t,ct=1; cin>>t;
  while(t--)
  {
    int n; cin>>n;
    vi scr(n+1,0), dp(n+1,0), vis(n+1,0);
    F(0,n,i){cin>>scr[i+1];}

    map<int,vi> graph;
    F(0,n-1,i){
      int x, y;
      cin>>x>>y;
      if(scr[x]>scr[y]){
        graph[x].push_back(y);
      }
      else if(scr[x]<scr[y]){
        graph[y].push_back(x);
      }
    }

    F(1,n+1,i){
      if(vis[i]==0){
        dfs(graph,i,vis,dp);
      }
    }

    int ans = *max_element(all(dp));
    cout<<"Case #"<<ct<<": "<<ans<<"\n";
    ct++;
  }

}
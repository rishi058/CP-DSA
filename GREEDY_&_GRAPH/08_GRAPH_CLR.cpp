#include <bits/stdc++.h>
using namespace std;

/*
==> Q.) m - coloring graph (paint the graph such that color of adjacent vertex are always distinct)
==> This Algo gives --->
==> gives ans true/false i.e is it possible or not
==> no. of solutions possible.
==> Print all solutions.
*/

vector<vector<int>> ans;

//Function to check constraints
bool satisfyConstraints(int v, map<int,vector<int>> graph,vector<int> color, int c) {
  for(int x : graph[v]){
    if(color[x]==c){
      return false;
    }
  }
  return true;
}


/* A recursive utility function to solve m-coloring problem */
void m_Coloring(map<int,vector<int>> graph, int m,vector<int> color, int v) {
  //If all vertices are assigned a color
  if (v==graph.size()){
    ans.push_back(color);
  }
  if(v>graph.size()){
    return;
  }

  //Try different colors to vertex v
  for (int c = 1; c <= m; c++) {

    // Check if given color is valid 
    if (satisfyConstraints(v, graph, color, c)) {
      color[v] = c;

      //Assign colors to rest of the vertices
      m_Coloring(graph, m, color, v + 1);

      //Backtrack
      color[v] = 0;
    }
  }
  // If no color can be assigned
  return ;
}

int main() {
  
  int n, m; // n = no. of edges, m = no. of colors.
  cin>>n>>m;

  map<int,vector<int>> graph;

  for(int i=0; i<n; i++){
    int x, y;
    cin>>x>>y;

    x--; y--;

    graph[x].push_back(y);
    graph[y].push_back(x);
  }

  int s = graph.size();
  vector<int> color(s, 0);
  m_Coloring(graph, m, color, 0);

  // for(auto x : graph){
  //   cout<<x.first<<" - ";
  //   for(int z : x.second){
  //     cout<<z<<" ";
  //   }
  //   cout<<"\n";
  // }

  cout<<ans.size()<<"\n";

  for(auto vec : ans){
    for(int x : vec){
      cout<<x<<" ";
    }
    cout<<"\n";
  }

}
/*
5 3
1 2
1 3
1 4
3 4
2 4
*/
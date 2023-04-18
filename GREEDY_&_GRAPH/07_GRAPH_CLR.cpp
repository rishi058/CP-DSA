#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

// Number of vertices in the Adj_matrix
#define V 4

//Function to check constraints
bool satisfyConstraints(int v, bool Adj_matrix[V][V],vector<int> color, int c) {
  for (int i = 0; i < V; i++) {
    if (Adj_matrix[v][i] && c == color[i])
      return false;
  }
  return true;
}

/* A recursive utility function to solve m-coloring problem */
void m_Coloring_Helper(bool Adj_matrix[V][V], int m,vector<int> color, int v) {

  //If all vertices are assigned a color
  if (v == V){
    ans.push_back(color);
  }
  if(v>V){
    return;
  }
    // return true;

  //Try different colors to vertex v
  for (int c = 1; c <= m; c++) {

    // Check if given color is valid 
    if (satisfyConstraints(v, Adj_matrix, color, c)) {
      color[v] = c;

      //Assign colors to rest of the vertices
      m_Coloring_Helper(Adj_matrix, m, color, v + 1);

      //Backtrack
      color[v] = 0;
    }
  }

  // If no color can be assigned
  return ;
}

void solve(bool Adj_matrix[V][V], int m){
  vector<int> color(V,0);
  m_Coloring_Helper(Adj_matrix, m, color, 0);
}

int main() {
  // The adjacency matrix of the graph
  bool Adj_matrix[V][V] = {
    {0,1,1,1},
    {1,0,0,1},
    {1,0,0,1},
    {1,1,1,0},
  };

  // Number of colors
  int m = 3;
  // vector<int> color(V,0);
  solve(Adj_matrix,m);
  
  cout<<ans.size()<<"\n";

  for(auto vec : ans){
    for(int x : vec){
      cout<<x<<" ";
    }
    cout<<"\n";
  }

}
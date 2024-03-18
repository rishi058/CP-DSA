#include <bits/stdc++.h>
using namespace std;

/*
DIAMETER OF A TREE --->
longest path b/w any two vertices...

Approach -->
Run dfs with any vertex as root node and find the vertex/node which has max
depth, and then again run  dfs to find the length of deepest node by taking
previously obtained node as the root node...

*/

const int N=1e5+7;
vector<int> g[N];
int depth[N];

void dfs(int vertex, int par=0){

    for(int child : g[vertex]){
        if(child==par){continue;}
        
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
    }
    
}

int main()
{
    int n; cin>>n;  // n = no. of vertex.

    for(int i=0; i<n-1; i++){   // n-1 = no. of edges..
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);

    }
    
    dfs(1);

    int mx = *max_element(depth, depth+n+1);
    int mx_node;

    for(int i = 1; i<=n; i++){
        if(depth[i]==mx){mx_node=i; break;}
    }

    for(int i = 1; i<=n; i++){
        depth[i] = 0;
    }

    dfs(mx_node);

    cout<<*max_element(depth, depth+n+1)<<"\n";

}

/*
13
1 2
1 3
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9
4 10
10 11
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define tuple array<int, 3>
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

Types of DFS Traversal in tree :-

PreOrder  :   root, left subtree, right subtree. 
PostOrder :   left subtree, root, right subtree.  [Not used in adj list/matrix, used in struct types]
Inorder   :   left subtree, right subtree, root.

In Graph : preOrder is used mostly.

*/

/*   ********** SAMPLE GRAPH INPUT EXAMPLE **********
6 9
1 3
1 5
3 5
3 4
3 6
3 2
2 6
4 6
5 6
*/

// Note this dfs is used for both tree and Graph : U can remove 'vis' when using in tree.
 
void dfs(int root, vector<bool>&vis, vector<int>adj[]){

    vis[root] = 1;

    // cout<<root<<" -> ";      // PreOrder

    for(int child : adj[root]){
        if(!vis[child]){
            dfs(child, vis, adj);
        }

    }
 
    // cout<<root<<" -> ";      // InOrder

}

void dfs_tree_sample(int vertex, vector<int>g[]){
    /*
    take action on vertex after entering vertex                   -->niche jaa raha h
    */
    for(int child : g[vertex]){
        /*
        take action on child before entering child node           -->niche jaa raha h
        */
        dfs_tree_sample(child, g);
        /*
        take acton on child after entering child node              -->upar aa raha h 
        */
    }
    /*
    take action on vertex before exiting the vertex                 -->upar aa raha h
    */
}

int32_t main()
{
    RISHI
    int T = 1;
    // cin>>T;
    while(T--)
    {
        int n, m;    // ct of vertices, edges   [ In Tree : ct_edge = ct_vertex-1 ]
        cin>>n>>m;

        vector<int> adj[n+1];
        for(int i=0; i<m; i++){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);        // if graph isn't bidirectional or it is a tree comment this line.
        }
        
        vector<bool> vis(n+1, 0);
        dfs(1, vis, adj);
    }

}





//      ██╗  █████╗  ██╗    ██████╗ ██╗  ██╗ ██████╗  ███████╗ ███████╗   ██████╗   █████╗  ███╗   ███╗
//      ██║ ██╔══██╗ ██║   ██╔════╝ ██║  ██║ ██╔══██╗ ██╔════╝ ██╔════╝   ██╔══██╗ ██╔══██╗ ████╗ ████║
//      ██║ ███████║ ██║   ╚█████╗  ███████║ ██████╔╝ █████╗   █████╗     ██████╔╝ ███████║ ██╔████╔██║
// ██╗  ██║ ██╔══██║ ██║    ╚═══██╗ ██╔══██║ ██╔══██╗ ██╔══╝   ██╔══╝     ██╔══██╗ ██╔══██║ ██║╚██╔╝██║
// ╚█████╔╝ ██║  ██║ ██║   ██████╔╝ ██║  ██║ ██║  ██║ ███████╗ ███████╗   ██║  ██║ ██║  ██║ ██║ ╚═╝ ██║
//  ╚════╝  ╚═╝  ╚═╝ ╚═╝   ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚══════╝ ╚══════╝   ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝     ╚═╝
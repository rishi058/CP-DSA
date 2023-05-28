#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
#define F(a,b,i) for (int i = a; i < b; i++)
#define Rev(a,b,i) for (int i = a; i >= b; i--)
#define RISHI ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define inf LONG_LONG_MAX
#define Min LONG_LONG_MIN

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

// Prefect Binary Tree -> each node have 2 or 0 child. 

void bfsTraversal(vector<int>& tree) {
    int size = tree.size();
    queue<int> q;

    // Start BFS from the root node (index 1)
    q.push(1);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // Process current node
        cout << tree[node] << " ";

        // Push left child if within bounds
        if (2 * node < size)
            q.push(2 * node);

        // Push right child if within bounds
        if (2 * node + 1 < size)
            q.push(2 * node + 1);
    }
}

void dfs(int node, int par, vector<int>& tree, vector<int> &dp) {  // dp is used to store prefix sum of tree(ignore).
    int size = tree.size();
    if (node >= size){return;}

    dp[node] = tree[node] + dp[par];
    // cout << tree[node] << " ";

    dfs(2 * node, node, tree, dp);        // left child
    dfs(2 * node + 1, node, tree, dp);    // right child
}

int32_t main(){

    vector<int> tree = {0,1,5,2,2,3,3,1};  // 1 based indexing. 1 is the root node, tree[i] = value of ith node

    int n = tree.size();

    vector<int> dp(n, 0);

    int size = tree.size();
    dfs(1, 0, tree, dp);

    int sum = 0, mx = 0;
    for(int i=(n/2); i<n; i++){    // iterating the leaf nodes
        sum += dp[i];
        mx = max(mx, dp[i]);
    }
    int ans = (n/2)*mx - sum;    // when total no. of node is n, no. of leaf nodes = (n+1)/2. 
    cout<<ans<<"\n";

}



// ███████╗██╗███╗   ██╗██╗███████╗██╗  ██╗    ██╗    ██╗██╗  ██╗ █████╗ ████████╗    ██╗   ██╗ ██████╗ ██╗   ██╗    ███████╗████████╗ █████╗ ██████╗ ████████╗    ██╗
// ██╔════╝██║████╗  ██║██║██╔════╝██║  ██║    ██║    ██║██║  ██║██╔══██╗╚══██╔══╝    ╚██╗ ██╔╝██╔═══██╗██║   ██║    ██╔════╝╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝    ██║
// █████╗  ██║██╔██╗ ██║██║███████╗███████║    ██║ █╗ ██║███████║███████║   ██║        ╚████╔╝ ██║   ██║██║   ██║    ███████╗   ██║   ███████║██████╔╝   ██║       ██║
// ██╔══╝  ██║██║╚██╗██║██║╚════██║██╔══██║    ██║███╗██║██╔══██║██╔══██║   ██║         ╚██╔╝  ██║   ██║██║   ██║    ╚════██║   ██║   ██╔══██║██╔══██╗   ██║       ╚═╝
// ██║     ██║██║ ╚████║██║███████║██║  ██║    ╚███╔███╔╝██║  ██║██║  ██║   ██║          ██║   ╚██████╔╝╚██████╔╝    ███████║   ██║   ██║  ██║██║  ██║   ██║       ██╗
// ╚═╝     ╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝     ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝          ╚═╝    ╚═════╝  ╚═════╝     ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝       ╚═╝
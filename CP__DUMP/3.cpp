#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, int par, vector<int>& tree, vector<int> &dp) {
    int size = tree.size();
    if (node >= size){return;}

    dp[node] = tree[node] + dp[par];
    // cout << tree[node] << " ";

    dfs(2 * node, node, tree, dp);
    dfs(2 * node + 1, node, tree, dp);
}

int main() {
    vector<int> tree = {0,1,5,2,2,3,3,1};
    int n = tree.size();

    vector<int> dp(n, 0);

    int size = tree.size();
    dfs(1, 0, tree, dp);

    int sum = 0, mx = 0;
    for(int i=(n/2); i<n; i++){
        sum += dp[i];
        mx = max(mx, dp[i]);
    }
    int ans = (n/2)*mx - sum;
    cout<<ans<<"\n";

}

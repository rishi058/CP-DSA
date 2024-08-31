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

void rotate180(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    for (int i = 0; i < (n + 1) / 2; ++i) {
        for (int j = 0; j < m; ++j) {
            swap(grid[i][j], grid[n-1-i][m-1-j]);
        }
    }

    // If the number of rows and columns are odd, we need to swap the middle row and column separately
    if (n % 2 != 0) {
        int midRow = n / 2;
        for (int j = 0; j < m / 2; ++j) {
            swap(grid[midRow][j], grid[midRow][m-1-j]);
        }
    }
}

int solve(vector<vector<int>>& grid, vector<vector<pair<int, int>>> &parent){
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int j = 1; j < m; j++) {
        if (grid[0][j] == -1) {
            break;
        }
        dp[0][j] = dp[0][j - 1] + grid[0][j];
        parent[0][j] = {0, j - 1};
    }

    for (int i = 1; i < n; i++) {
        if (grid[i][0] == -1) {
            break;
        }
        dp[i][0] = dp[i - 1][0] + grid[i][0];
        parent[i][0] = {i - 1, 0};
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (grid[i][j] == -1) {
                dp[i][j] = -1;
            } else {
                if (dp[i - 1][j] != -1 ) {
                    if (dp[i][j] < dp[i - 1][j] + grid[i][j]) {
                        dp[i][j] = dp[i - 1][j] + grid[i][j];
                        parent[i][j] = {i - 1, j};
                    }
                }
                if (dp[i][j - 1] != -1) {
                    if (dp[i][j] < dp[i][j - 1] + grid[i][j]) {
                        dp[i][j] = dp[i][j - 1] + grid[i][j];
                        parent[i][j] = {i, j - 1};
                    }
                }
            }
        }
    }

    if(dp[n - 1][m - 1] == -1) {
        return 0;
    }

    return dp[n - 1][m - 1];

}

int updateGrid(vector<vector<pair<int, int>>> parent, vector<vector<int>>& grid){
    int n = grid.size(), m = grid[0].size();
    int x = n - 1, y = m - 1;
    while (x != -1 && y != -1) {
        if (grid[x][y] == 1) {
            grid[x][y] = 0;  // Update the grid cell to 0
        }
        pair<int, int> p = parent[x][y];
        x = p.first;
        y = p.second;
    }
}

int collectMax(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();

    if (grid[0][0] == -1 || grid[n - 1][m - 1] == -1) {
        return 0;
    }

    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));

    int ans = solve(grid, parent);

    // if(ans==-1){return -1;}

    // updateGrid(parent, grid);

    // rotate180(grid);

    // ans += solve(grid, parent);

    return ans;

}

int32_t main()
{
    RISHI
    int T = 1;
    // cin>>T;
    while(T--)
    {
        vector<vi> v = {{1,0},{-1,0}};
        cout<<collectMax(v);

        
    }

}


//      ██╗  █████╗  ██╗    ██████╗ ██╗  ██╗ ██████╗  ███████╗ ███████╗   ██████╗   █████╗  ███╗   ███╗
//      ██║ ██╔══██╗ ██║   ██╔════╝ ██║  ██║ ██╔══██╗ ██╔════╝ ██╔════╝   ██╔══██╗ ██╔══██╗ ████╗ ████║
//      ██║ ███████║ ██║   ╚█████╗  ███████║ ██████╔╝ █████╗   █████╗     ██████╔╝ ███████║ ██╔████╔██║
// ██╗  ██║ ██╔══██║ ██║    ╚═══██╗ ██╔══██║ ██╔══██╗ ██╔══╝   ██╔══╝     ██╔══██╗ ██╔══██║ ██║╚██╔╝██║
// ╚█████╔╝ ██║  ██║ ██║   ██████╔╝ ██║  ██║ ██║  ██║ ███████╗ ███████╗   ██║  ██║ ██║  ██║ ██║ ╚═╝ ██║
//  ╚════╝  ╚═╝  ╚═╝ ╚═╝   ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚══════╝ ╚══════╝   ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝     ╚═╝
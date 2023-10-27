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
You are given an n x n grid representing the map of a forest. Each square is either empty or
has a tree. Your task is to process q queries of the following types:
1. Change the state (empty/tree) of a square.
2. How many trees are inside a rectangle in the forest?
*/

/*
Forest Queries II  [CSES]
Range Sum Query 2D - Mutalble [LeetCode],
 
Can be solved using BIT / 2d segment tree
T.C of update =    [ O(log(m)) + O(log(n)) ] 
T.C of query  =  4*[ O(log(m)) + O(log(n)) ]
 
Can also be solved using DP.
But T.C = O(m) + O(n)
*/
 
class NumMatrix {
    vector<vector<int>> tree;
    vector<vector<int>> nums;
    int n, m;
 
public:
 
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        m = matrix.size();
        n = matrix[0].size();
        tree = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        nums = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                update(i, j, matrix[i][j]);
            }
        }
    }
 
    void update(int row, int col, int val) {
        if (m == 0 || n == 0) return;
        int delta = val - nums[row][col];
        nums[row][col] = val;
        for (int i = row + 1; i <= m; i += i & -i) {
            for (int j = col + 1; j <= n; j += j & -j) {
                tree[i][j] += delta;
            }
        }
    }
 
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (m == 0 || n == 0) return 0;
        return sum(row2 + 1, col2 + 1) + sum(row1, col1) - sum(row1, col2 + 1) - sum(row2 + 1, col1);
    }
 
    int sum(int row, int col) {
        int sum = 0;
        for (int i = row; i > 0; i -= i & -i) {
            for (int j = col; j > 0; j -= j & -j) {
                sum += tree[i][j];
            }
        }
        return sum;
    }
};
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        int n, q;
        cin>>n>>q;
 
        vector<vector<int>> grid(n, vector<int>(n,0));
 
        F(0,n,i){
            F(0,n,j){
                char ch; cin>>ch;
                if(ch=='*'){
                    grid[i][j] = 1;
                }
            }
        }
 
        NumMatrix temp(grid);
 
        while(q--){
            int type; cin>>type;
            if(type==1){               // change the state;
                int i, j;
                cin>>i>>j;
                i--; j--;
                int new_val = 1 - grid[i][j];
                grid[i][j] = new_val;
                temp.update(i,j,new_val);
            }
            else{
                int x1, y1, x2, y2;
                cin>>x1>>y1>>x2>>y2;
 
                x1--; y1--; x2--; y2--;
 
                int ans = temp.sumRegion(x1, y1, x2, y2);
                cout<<ans<<"\n";
            }
        }
 
 
        
    }
 
}

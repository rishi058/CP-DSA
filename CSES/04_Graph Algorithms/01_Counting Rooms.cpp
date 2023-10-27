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
 
/*---------------------------------------->   MAGIC STARTS   <--------------------------------------------*/

/*
You are given a map of a building, and your task is to count the number of its rooms. The
size of the map is n x m squares, and each square is either floor or wall. You can walk left,
right, up, and down through the floor squares.
*/

vector<pair<int,int>> moves = {{1,0},{0,1},{-1,0},{0,-1}};
 
bool isVaild(int i, int j, int n, int m){
    if(i<0 || j<0 || i>=n || j>=m){return 0;}
    return 1;
}
 
void dfs(int i, int j, vector<string> &grid, vector<vector<bool>> &vis){
    vis[i][j] = 1;
    for(auto mov : moves){
        int x = mov.first+i, y = mov.second+j;
        if(isVaild(x,y,grid.size(), grid[0].size())){
            if(grid[i][j]=='.' && vis[x][y]==0){
                dfs(x,y,grid,vis);
            }
        }
    }
}
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        int n, m;
        cin>>n>>m;
 
        vector<string> grid(n);
        F(0,n,i){cin>>grid[i];}
 
        vector<vector<bool>> vis(n, vector<bool>(m,0));
 
        int ans = 0;
        F(0,n,i){
            F(0,m,j){
                if(grid[i][j]=='.' && vis[i][j]==0){
                    dfs(i,j,grid,vis);
                    ans++;
                }
            }
        }
 
        cout<<ans;
        
    }
 
}

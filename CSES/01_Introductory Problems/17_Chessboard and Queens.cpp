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
Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an 
additional challenge, each square is either free or reserved, and you can only place queens on the free squares.
However, the reserved squares do not prevent queens from attacking each other.
*/ 

int n=8;
vector<vector<int>> board;
vector<string> v;
int ans = 0;
 
 
bool is_safe(int row, int col){
 
    int x = row, y = col;
    //check for same row
    while(y>=0){
        if(board[x][y]==1){return false;}
        y--;
    }
 
    int xx = row, yy = col;
    //check for diagonal
    while(xx>=0 && yy>=0){
        if(board[xx][yy]==1){return false;}
        xx--; yy--;
    }
 
    int a = row, b = col;
    //check for diagonal
    while(a<n && b>=0){
        if(board[a][b]==1){return false;}
        a++; b--;
    }
 
    return true;
 
}
 
 
 
void solve(int col, int n){
 
    // base case (if every col is filled)
    if(col == n){
        ans++;
        return;
    }
 
    //put queen in every row of diff col..
    for(int row = 0; row<n; row++){
        if(v[row][col]=='*'){continue;}
        if(is_safe(row,col)){
 
            // if placing queen is safe
            board[row][col] = 1;
 
            solve(col+1, n);
 
            //backtrack
            board[row][col] = 0;
        }
    }
 
 
}
 
 
int32_t main()
{
    RISHI
 
    for(int i=0; i<n; i++){
        vector<int> temp(n, 0);
        board.push_back(temp);
    }
 
    F(0,8,i){
        string x; cin>>x;
        v.push_back(x);
    }
 
    solve(0, n);
    
    cout<<ans;
 
}

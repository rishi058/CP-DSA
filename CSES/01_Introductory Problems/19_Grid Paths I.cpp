#include <bits/stdc++.h>
using namespace std;
 
// #define int long long
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
There are 88418 paths in a 7 x 7 grid from the upper-left square to the lower-left square.
Each path corresponds to a 48-character description consisting of characters D (down), u
(up), L (left) and R (right).

You are given a description of a path which may also contain characters ? (any direction). Your task is
to calculate the number of paths that match the description.
*/

const int n = 7;
const int mx = n*n - 1;
int ans = 0;
bool vis[n][n];
string path;
 
 
bool valid(int x, int y){
    if(x<0 || y<0 || x>=n || y>=n){return 0;}
    if(vis[x][y]==1){return 0;}
    return 1;
}
 
void move(int x, int y, int steps){
    if(x==(n-1) && y==0){                   // opt - 1
        if(steps==mx){ans++;}
        return ;
    }
 
    // if you hit a wall or a path (can only go left or right); return  --? opt 2+3
    if (((x + 1 == n || (vis[x - 1][y] && vis[x + 1][y])) && y - 1 >= 0 && y + 1 < n && !vis[x][y - 1] && !vis[x][y + 1])){
        return ;
    }
    if(((y + 1 == n || (vis[x][y - 1] && vis[x][y + 1])) && x - 1 >= 0 && x + 1 < n && !vis[x - 1][y] && !vis[x + 1][y])){
        return ;
    }
    if(((x == 0 || (vis[x + 1][y] && vis[x - 1][y])) && y - 1 >= 0 && y + 1 < n && !vis[x][y - 1] && !vis[x][y + 1])){
        return ;
    }
    if(((y == 0 || (vis[x][y + 1] && vis[x][y - 1])) && x - 1 >= 0 && x + 1 < n && !vis[x - 1][y] && !vis[x + 1][y])){
        return;
    }
 
    vis[x][y] = true;
 
    int new_x = x+1, new_y = y;
    if(valid(new_x, new_y)){                            //down
        if(path[steps]=='?' || path[steps]=='D'){       // opt - 4
            move(new_x,new_y,steps+1);
        }
    }
 
    new_x = x; new_y = y-1;
    if(valid(new_x, new_y)){                            // Left
        if(path[steps]=='?' || path[steps]=='L'){
            move(new_x,new_y,steps+1);
        }
    }
 
    new_x = x-1; new_y = y;
    if(valid(new_x, new_y)){                            // up
        if(path[steps]=='?' || path[steps]=='U'){
            move(new_x,new_y,steps+1);
        }
    }
 
    new_x = x; new_y = y+1;
    if(valid(new_x, new_y)){                            // right
        if(path[steps]=='?' || path[steps]=='R'){
            move(new_x,new_y,steps+1);
        }
    }
 
    vis[x][y] = false;
}
 
 
int32_t main()
{
    cin>>path;
    int steps = 0;
    move(0, 0,steps);
    cout<<ans<<"\n";
}
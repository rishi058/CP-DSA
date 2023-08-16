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

const int n = 7;
int mx = 48;
bool vis[n][n];
int res = 0;
string path;

bool valid(int x, int y){
    if(x<0 || y<0 || x>=n || y>=n){return 0;}
    if(vis[x][y]==1){return 0;}
    return 1;
}
 
void move(int x, int y, int steps)
{
    if (x == n - 1 && y == 0){
        if(steps==mx){res++;}
        return ;
    }
 
    // if you hit a wall or a path (can only go left or right); return
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
 
    vis[x][y] = 1;

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
 
    vis[x][y] = 0;
}
 

int32_t main()
{
    RISHI
    cin>>path;

    move(0,0,0);
    cout<<res;
   

}



// ███████╗██╗███╗   ██╗██╗███████╗██╗  ██╗    ██╗    ██╗██╗  ██╗ █████╗ ████████╗    ██╗   ██╗ ██████╗ ██╗   ██╗    ███████╗████████╗ █████╗ ██████╗ ████████╗    ██╗
// ██╔════╝██║████╗  ██║██║██╔════╝██║  ██║    ██║    ██║██║  ██║██╔══██╗╚══██╔══╝    ╚██╗ ██╔╝██╔═══██╗██║   ██║    ██╔════╝╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝    ██║
// █████╗  ██║██╔██╗ ██║██║███████╗███████║    ██║ █╗ ██║███████║███████║   ██║        ╚████╔╝ ██║   ██║██║   ██║    ███████╗   ██║   ███████║██████╔╝   ██║       ██║
// ██╔══╝  ██║██║╚██╗██║██║╚════██║██╔══██║    ██║███╗██║██╔══██║██╔══██║   ██║         ╚██╔╝  ██║   ██║██║   ██║    ╚════██║   ██║   ██╔══██║██╔══██╗   ██║       ╚═╝
// ██║     ██║██║ ╚████║██║███████║██║  ██║    ╚███╔███╔╝██║  ██║██║  ██║   ██║          ██║   ╚██████╔╝╚██████╔╝    ███████║   ██║   ██║  ██║██║  ██║   ██║       ██╗
// ╚═╝     ╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝     ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝          ╚═╝    ╚═════╝  ╚═════╝     ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝       ╚═╝
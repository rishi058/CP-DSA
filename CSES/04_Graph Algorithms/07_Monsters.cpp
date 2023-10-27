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
#define inf INT_MAX
#define Min LONG_LONG_MIN
 
typedef long double ld;
typedef vector<int> vi;
 
/*---------------------------------------->   MAGIC STARTS   <--------------------------------------------*/

/*
You and some monsters are in a labyrinth. When taking a step to some direction in the
labyrinth, each monster may simultaneously take one as well. Your goal is to reach one of
the boundary squares without ever sharing a square with a monster.
Your task is to find out if your goal is possible, and if it is, print a path that you can follow.
Your plan has to work in any situation; even if the monsters know your path beforehand.
*/

unordered_map<char,pair<int,int>> moves = {{'D',{1,0}},{'U',{-1,0}},{'L',{0,-1}},{'R',{0,1}}};
 
bool isVaild(int i, int j, int n, int m){
    if(i<0 || j<0 || i>=n || j>=m){return 0;}
    return 1;
}
 
string generate(int i, int j, int a, int b, vector<vector<char>> trace){
    string ans;
    while(1){
        ans.push_back(trace[i][j]);
        int x = i - moves[trace[i][j]].first;
        int y = j - moves[trace[i][j]].second;
        if(x==a && y==b){break;}
        i = x; j = y;
    }
    reverse(all(ans));
    return ans;
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
        vector<vector<int>> level(n, vector<int>(m,inf));
 
        pair<int,int> start;
        queue<pair<int,int>> q;
 
        F(0,n,i){
            F(0,m,j){
                if(grid[i][j]=='A'){start.first=i, start.second=j;}
                if(grid[i][j]=='M'){q.push({i,j}); vis[i][j]=1; level[i][j]=0;}
            }
        }        
 
        if(start.first==0 || start.first==(n-1) || start.second==0 || start.second==(m-1)){cout<<"YES\n0\n"; continue;}
        int lvl = 1;
 
        while(!q.empty()){
            int k = q.size();
            for(int i=0; i<k; i++){
                int x = q.front().first, y = q.front().second;
                q.pop();
 
                for(auto mov : moves){
                    int i = x+mov.second.first, j = y+mov.second.second;
                    if(isVaild(i,j,n,m)){
                        if(grid[i][j]!='#' && vis[i][j]==0){
                            vis[i][j] = 1;
                            q.push({i,j});
                            level[i][j] = lvl;
                        }
                    }
                }                
            }
            lvl++;
        }
 
        lvl = 1;
        vis.assign(n, vector<bool>(m,0));
        q.push({start.first, start.second});
        vis[start.first][start.second] = 1;
        vector<vector<char>> trace(n, vector<char>(m, '.'));
 
        bool res = 0;
        pair<int,int> end;
 
        while(!q.empty()){
            int k = q.size();
            for(int i=0; i<k; i++){
                int x = q.front().first, y = q.front().second;
                q.pop();
 
                for(auto mov : moves){
                    int i = x+mov.second.first, j = y+mov.second.second;
                    if(isVaild(i,j,n,m)){
                        if(grid[i][j]=='.' && vis[i][j]==0 && level[i][j]>lvl){
                            // cout<<i<<" "<<j<<"\n";
                            vis[i][j] = 1;
                            trace[i][j] = mov.first;
                            if(i==0 || j==0 || i==(n-1) || j==(m-1)){
                                end.first = i, end.second = j;
                                res = 1;
                                break;
                            }
                            q.push({i,j});
                        }
                    }
                }                
 
                if(res){break;}
            }
            if(res){break;}
            lvl++;
        }
 
        // for(auto vec : level){
        //     print(vec);
        // }
        if(res){
            cout<<"YES\n";
            string ans = generate(end.first, end.second, start.first, start.second, trace);
            cout<<ans.size()<<"\n";
            cout<<ans;
        }
        else{
            cout<<"NO\n";
        }
        
    }
 
}
 
 

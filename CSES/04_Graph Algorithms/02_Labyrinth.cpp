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
You are given a map of a labyrinth, and your task is to find a path from start to end. You can
walk left, right, up and down.
*/

unordered_map<char,pair<int,int>> moves = {{'D',{1,0}},{'U',{-1,0}},{'L',{0,-1}},{'R',{0,1}}};
 
bool isVaild(int i, int j, int n, int m){
    if(i<0 || j<0 || i>=n || j>=m){return 0;}
    return 1;
}
 
string generate(int i, int j, vector<vector<char>> trace){
    string ans;
    while(trace[i][j]!='.'){
        ans.push_back(trace[i][j]);
        int x = i - moves[trace[i][j]].first;
        int y = j - moves[trace[i][j]].second;
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
        vector<vector<char>> trace(n, vector<char>(m,'.'));
 
        queue<pair<int,int>> q;
        pair<int,int> end;
 
        F(0,n,i){
            F(0,m,j){
                if(grid[i][j]=='A'){
                    grid[i][j]='#';
                    q.push({i,j});
                }
                if(grid[i][j]=='B'){
                    end.first=i;
                    end.second=j;
                }
            }
        }
 
        int lvl = 1;
        bool ok = 0;
 
        while(!q.empty()){
            int k = q.size();
 
            for(int i=0; i<k; i++){
                int x = q.front().first, y = q.front().second;
                q.pop();
 
                for(auto mov : moves){
                    int i = mov.second.first+x, j = mov.second.second+y;
                    if(isVaild(i,j,n,m)){
                        if(grid[i][j]!='#' && vis[i][j]==0){
                            vis[i][j]=1;
                            q.push({i,j});
                            trace[i][j] = mov.first;
                            if(grid[i][j]=='B'){ok=1; break;}
                        }
                    }
                }
                if(ok){break;}
            }
 
            if(ok){break;}
            lvl++;
        }
 
        if(ok){
            cout<<"YES\n";
            cout<<lvl<<"\n";
            cout<<generate(end.first, end.second, trace);
        }
        else{
            cout<<"NO\n";
        }
        
    }
 
}

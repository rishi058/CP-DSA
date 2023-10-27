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
 
/*------------------------ 𝑃𝑟𝑎𝑐𝑡𝑖𝑐𝑒 𝑙𝑖𝑘𝑒 𝑦𝑜𝑢'𝑣𝑒 𝑛𝑒𝑣𝑒𝑟 𝑤𝑜𝑛. 𝑃𝑒𝑟𝑓𝑜𝑟𝑚 𝑙𝑖𝑘𝑒 𝑦𝑜𝑢'𝑣𝑒 𝑛𝑒𝑣𝑒𝑟 𝑙𝑜𝑠𝑡. ------------------------*/
 
/*
Given a starting position of a knight on an 8 x 8 chessboard, your task is to find a sequence
of moves such that it visits every square exactly once.
On each move, the knight may either move two steps horizontally and one step vertically, or
one step horizontally and two steps vertically.

Note :- Normal Bactracking gives tle(t.c = 8^64);
 
Warnsdorf's Algorithm ->
1. We always move to an unvisited square with minimal degree (minimum number of unvisited adjacent).
-> degree[i][j] = no. of unvisited sqaures i can go to, if I am at (i,j)
*/
 
typedef array<int,3> triple;
const int N = 8;
bool vis[N][N];
vector<vi> ans(N, vector<int>(N,0)), deg(N, vector<int>(N,0));
 
vector<pair<int,int>> moves = {{2,1},{-2,1},{2,-1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
 
bool isValid(int i, int j){
	if(i<0 || j<0 || i>=N || j>=N){return 0;}
	return 1;
}
 
void mark(int x, int y, int ct){
    ans[x][y] = ct;
    vis[x][y] = 1;
    for(auto [a,b] : moves){
		int i = x+a, j = y+b;
		if(isValid(i,j) && !vis[i][j]){
			deg[i][j]--;
		}
	}
}
 
void unmark(int x, int y){
	ans[x][y] = -1;
    vis[x][y] = 0;
    for(auto [a,b] : moves){
		int i = x+a, j = y+b;
		if(isValid(i,j) && !vis[i][j]){
			deg[i][j]++;
		}
	}
}
 
bool solve(int i, int j, int ct){
	mark(i, j, ct);
	if(ct==64){return 1;}
	
	vector<triple> options;
 
	for(auto [a,b] : moves){
		int x = i+a, y = j+b;
 
		if(isValid(x,y) && !vis[x][y]){
			options.push_back({deg[x][y], x, y});
		}
	}
 
	sort(all(options));
 
	for(auto [deg, x, y] : options){
		if(solve(x, y, ct+1)){return 1;}
	}
 
	unmark(i,j);
	return 0;
}
 
int32_t main()
{
	RISHI
	int T = 1;
	while(T--)
	{
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				for(auto [a,b] : moves){
					int x = i+a, y = j+b;
					if(isValid(x,y)){
						deg[x][y]++;
					}
				}
			}
		}
 
		int i, j;
		cin>>i>>j;
		i--; j--;
		swap(i,j);
 
		solve(i,j,1);
 
		for(auto vec : ans){
			print(vec);
		}
	}
 
}

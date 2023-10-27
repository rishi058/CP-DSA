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
contains a tree. The upper-left square has coordinates (1, 1), and the lower-right square has
coordinates (n, n).
Your task is to process q queries of the form: how many trees are inside a given rectangle in
the forest?
*/

int32_t main()
{
	RISHI
	int T = 1;
	while(T--)
	{
		int n, q;
		cin>>n>>q;
 
		vector<string> grid(n);
		F(0,n,i){cin>>grid[i];}
 
		int dp[n][n];
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(grid[i][j]=='*'){
					dp[i][j] = 1;
				}
				else{
					dp[i][j] = 0;
				}
			}
		}
 
 
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(i==0 && j==0){continue;}
				else if(i==0){dp[i][j] += dp[i][j-1];}
				else if(j==0){dp[i][j] += dp[i-1][j];}
				else{
					dp[i][j] += (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]);
				}
			}
		}
 
		while(q--){
			int x1, y1, x2, y2;
			cin>>x1>>y1>>x2>>y2;
 
			x1--; y1--; x2--; y2--;   
 
			// 4 corners are -> UL, UR, DL, DR.
			int UL = 0, UR = 0, DL = 0, DR = 0;
 
			DR = dp[x2][y2];
			if(x1!=0 && y1!=0){UL = dp[x1-1][y1-1];}
			if(y1!=0){DL = dp[x2][y1-1];}
			if(x1!=0){UR = dp[x1-1][y2];}
 
			int ans = DR - UR - DL + UL;
			cout<<ans<<"\n";
		}
		
	}
 
}

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
Given an array of n integers, your task is to process q queries of the form: what is the
minimum value in range [a, b]?

3 Appraoches :-
1. Segement_tree [nlogn preprocessing time, logn for queries, 4*n space] -> updates are possible.
2. Sparse Table  [nlogn nlogn preprocessing time, O(1) for lookup]  -> updates aren't possible.
3. Sqrt Decomposition.
*/
 
const int N = 2e5+1;
const int logN = 20;
 
int dp[N][logN];
 
void pre(vector<int>v){
	int n = v.size();
 
	for(int i=0; i<n; i++){
		dp[i][0] = v[i];
	}
 
	for(int i = 1; i < logN; i++){
        for(int j = 0; j <= n-(1<<i); j++){
            dp[j][i] = min(dp[j][i-1], dp[j+(1<<(i-1))][i-1]);
		}
	}
}
 
int getMin(int l, int r){   // 0-based-indexing
	int len = r-l+1;
	int k = log2(len);
	return min(dp[l][k], dp[r-(1<<k)+1][k]);
}
 
int32_t main()
{
	RISHI
	int T = 1;
	while(T--)
	{
		int n, q;
		cin>>n>>q;
		vi v(n);
		F(0,n,i){cin>>v[i];}
		
		pre(v);
 
		while(q--){
			int l, r;
			cin>>l>>r;
			l--; r--;
			int ans = getMin(l,r);
			cout<<ans<<"\n";
		}
	}
 
}
 

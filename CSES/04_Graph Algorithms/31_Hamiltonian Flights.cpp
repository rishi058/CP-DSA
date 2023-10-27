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
There are n cities and m flight connections between them. You want to travel from Syrjälä to
Lehmälä so that you visit each city exactly once. How many possible routes are there?
*/

const int N = 20;
int dp[N][1<<N];
vector<int> adj[N];
 
int countWays(int node, int mask, int n){
	if(mask==(1<<n)-1 && node==n-1){return 1;}      // agar sabhi node visit kar liye h, and abhi n'th node par h,
	else if(node==n-1){return 0;}
	if(dp[node][mask]!=-1){return dp[node][mask];}
	
	int ways = 0;
	for(int child : adj[node]){
		if(!(mask & 1<<child)){
			ways += countWays(child, mask | (1<<child), n);
			ways %= mod;
		}
	}
 
	return dp[node][mask] = ways;
}
 
int32_t main()
{
	RISHI
	int T = 1;
	while(T--)
	{
		int n, m;
		cin>>n>>m;
 
		F(0,m,i){
			int u,v;
			cin>>u>>v;
			u--; v--;
			adj[u].push_back(v);
		}
 
		memset(dp, -1, sizeof(dp));
		int ans = countWays(0, 1, n);
		cout<<ans<<"\n";
	}
 
}
 

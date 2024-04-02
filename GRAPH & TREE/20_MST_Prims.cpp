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
CSES : Road Reperation.

There are n cities and m roads between them. Unfortunately, the condition of the roads is so
poor that they cannot be used. Your task is to repair some of the roads so that there will be
a decent route between any two cities.
For each road, you know its reparation cost, and you should find a solution where the total
cost is as small as possible.
*/


/*
 
Road Reperation :-
Approach :-
1. Build a MST (use Prim's algorithm bcz Kruskal's may give disconnected comp)
2. If all nodes aren't used in MST return -1;
3. return sum of wt of MST.
 
*/
 
const int N = 1e5+1;
vector<pair<int,int>> adj[N];
 
int spanningTree(int V){    // Striver's Code
	set<pair<int,int>> pq;
	vector<int> vis(V, 0);
 
	pq.insert({0, 0});  // {wt, node}
	int sum = 0;
 
	while (!pq.empty()) {
		int node =  pq.begin()->second;
        int wt   =  pq.begin()->first;
		pq.erase(pq.begin());
		
		if (vis[node] == 1) continue;
		
		vis[node] = 1;   // add it to the mst
		sum += wt;
		for (auto it : adj[node]) {
			int adjNode = it.first;
			int edW = it.second;
			if (!vis[adjNode]) {
				pq.insert({edW, adjNode});
			}
		}
	}
 
    int all = accumulate(all(vis), 0);
	if(all!=V){return -1;}
	return sum;
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
            int u, v, wt;
            cin>>u>>v>>wt;
            u--; v--;
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
 
        int ans = spanningTree(n);
 
        if(ans==-1){
			cout<<"IMPOSSIBLE\n";
		}
		else{
			cout<<ans<<"\n";
		}
    }
 
}

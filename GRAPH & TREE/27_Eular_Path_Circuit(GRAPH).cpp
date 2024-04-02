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
cses - Mail Delivery  [also check, cses : teleporters Path]

Your task is to deliver mail to the inhabitants of a city. For this reason, you want to find a
route whose starting and ending point are the post office, and that goes through every
street exactly once.

post office is located at crossing 1.
All streets are two-way streets.

This problem wants us to print a Eulerian circuit(which start @ 1) of a undirected graph.
T.C = O(V+E)
*/

/*
Eulerian Path is a path in a graph that visits every edge exactly once. 
Eulerian Circuit/Cycle/Tour is an Eulerian Path that starts and ends on the same vertex. 
 
For Undirected Graph ->
1. Eulerian Circuit =>  degree of each node should be even
2. Eulerain Path    =>  degree of (n-2) node should be even & degree of 2 node should be odd.
 
For Directed Graph ->
1. Eulerian Circuit =>  for each node indegree = outdegree
2. Eulerain Path    => 	for (n-2)'s node indegree = outdegree & for other 2 nodes (a). indegree = oudegree+1, (b). indegree + 1 = oudegree,

*/
 
const int N = 1e5+5;
vector<pair<int,int>> adj[N];
 
int32_t main()
{
	RISHI
	int T = 1;
	while(T--)
	{
		int n, m;
		cin>>n>>m;
 
		F(0,m,i){
			int u, v;
			cin>>u>>v;
			adj[u].push_back({v,i});
			adj[v].push_back({u,i});
		}
 
		// F(1,n+1,i){print2(adj[i]);}
 
		for(int i=1; i<=n; i++){
			if(adj[i].size()&1){
				cout<<"IMPOSSIBLE\n";
				return 0;
			}
		}
 
		vi vis(m+1,0), ans;
		
    	stack<int> st; st.push(1);
    	while(!st.empty()){
    	    int node = st.top();
			bool flag = 0;     // used to check if all edges related to 'v' is visited or not.
 
    	    while(!adj[node].empty()) {   
    	        auto [child, id] =  adj[node].back();
				adj[node].pop_back();                  // deleting the edge
 
    	        if (!vis[id]){    // if a certain edge isn't visited, take it.
					st.push(child); vis[id]=1;
					flag = 1;  break;
				}
    	    }
 
    	    if(flag==0){   // if every edge of v is visited
				ans.push_back(node); st.pop();
			}
    	}
 
		if(ans.size()!=m+1){
			cout<<"IMPOSSIBLE\n";
		}
		else{
			print(ans);
		}
		
	}
 
}

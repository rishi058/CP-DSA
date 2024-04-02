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
#define inf LONadj_LONadj_MAX
#define Min LONadj_LONadj_MIN
 
typedef long double ld;
typedef vector<int> vi;
 
/*---------------------------------------->   MAadjIC STARTS   <--------------------------------------------*/

/*
A game has n levels and m teleportes between them. You win the game if you move from
level 1 to level n using every teleporter exactly once.
Can you win the game, and what is a possible way to do it?

This problem wants us to print a Eulerian Path(which starts @ '1' & ends @ 'n') of a directed graph.
T.C = O(V+E)
*/


/*
for a Eulerian path(for a directed graph) to exists from 1 to n,
( in[1] = out[1] - 1 ) & ( in[n] = out[n] + 1 ) or (in[1] == out[1]) && (in[n]==out[n])
*/
 
const int N = 1e5+2;
vector<int> adj[N];
int ct_edge;
 
void dfs(int node, int par, vi &vis){
	vis[node] = 1;
	for(int child : adj[node]){
		ct_edge--;
		if(child==par || vis[child]){continue;}
		dfs(child, node, vis);
	}
}
 
int32_t main()
{
	RISHI
	int T = 1;
	while(T--)
	{
		int n, m;
		cin>>n>>m;
 
		ct_edge = m;
 
		vector<int> in_degree(n+1, 0), out_degree(n+1, 0);
 
		F(0,m,i){
			int u, v;
			cin>>u>>v;
			adj[u].push_back(v);
			in_degree[v]++;
			out_degree[u]++;
		}	
 
		vi unequal_node;
		F(1,n+1,i){
			if(in_degree[i]!=out_degree[i]){unequal_node.push_back(i);}
		}
 
		if(unequal_node.size()!=2 || unequal_node[0]!=1 || unequal_node[1]!=n){
			cout<<"IMPOSSIBLE\n";
			return 0;;
		}
 
		vi vis(n+1,0);
		dfs(1,0,vis);
 
		if( (vis[n] && ct_edge>0) || (!vis[n])){    // edge_case
			cout<<"IMPOSSIBLE\n"; return 0;
		}
 
		bool ok = 1;	
		// print(in_degree);
		// print(out_degree);
 
		ok &= (in_degree[1]==out_degree[1]-1);
		ok &= (in_degree[n]==out_degree[n]+1);
 
		if(!ok){
			if(in_degree[1]!=out_degree[1] || in_degree[n]!=out_degree[n]){   // edge_case
				cout<<"IMPOSSIBLE\n"; return 0;
			}
			
		}
 
		stack<int> st;
		vi ans;
		st.push(1);
		
		while(!st.empty()){
			int u = st.top();
        	if(!adj[u].empty()){
        	    int v = adj[u].back();
        	    adj[u].pop_back();
        	    st.push(v);
        	}
			else {
        	    ans.push_back(u);
        	    st.pop();
        	}
		}
 
		reverse(all(ans));
		print(ans);
				
	}
 
}
 

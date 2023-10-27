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

There are n cities and m flight connections. Your task is to check if you can travel from any
city to any other city using the available flights.
 
IDEA ->
The theorem used here is that if one vertex can both reach and be reached by all others,
then every vertex in this graph can reach all others.
--> this type of Graph is also known as strongly connected component [Kosaraju algo]..
 
Intuition For Kosaraju(Striver) -->
Pehle Dfs traversal store karlo..
Fir New Reverse Graph create karo..
Aur Node Sequence of dfs traversal se New Graph me dfs chalao. and jitna baar dfs chala utna answer hoga.
 
*/
 
const int N = 1e5+2;
vector<int> adj[N];
vector<int> adjT[N];  // reverser,transpose Graph
 
void dfs(int node, vector<bool>&vis, stack<int> &st){
    vis[node] = true;
	for(auto nbr: adj[node]){
	    if(!vis[nbr]){
	        dfs(nbr, vis, st);
	    }
	}
 
	st.push(node);  // stores dfs traversal sequence (can be @ start also + vector)
}
 
void revDfs(int node,  vector<bool> &vis){
    vis[node] = true; 
    for(auto nbr: adjT[node]){
        if(!vis[nbr]){
            revDfs(nbr, vis);
        }
    }
}
 
void kosaraju(int n){  // little modifed 4 this que.
    stack<int> st;
    vector<bool> vis1(n,0);
    vector<bool> vis2(n,0);
	
	 
    for(int i = 0; i < n; i++){
        if(!vis1[i]){dfs(i, vis1, st);}  // this line is changed from previous wrong submission
    }
 
	revDfs(st.top(), vis2);
 
	
	for(int i=0; i<n; i++){
		if(!vis2[i]){
			cout<<"NO\n";
			cout<<i+1<<" "<<st.top()+1<<"\n";  // this is also debugged
			return;
		}
	}
	
	cout<<"YES\n"; return;
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
			int u, v;
			cin>>u>>v;
			u--; v--;
			adj[u].push_back(v);
			adjT[v].push_back(u);
		}
 
		kosaraju(n);
    }
 
}

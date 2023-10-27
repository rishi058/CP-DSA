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
A game has n planets, connected by m teleporters. Two planets a and b belong to the same
kingdom exactly when there is a route both from a to b and from b to a. Your task is to
determine for each planet its kingdom.

It is a question from strongly connected component(SCC)
Appraoch =  Kosaraju Algo (refer - Striver)
*/
 
const int N = 1e5+2;
vector<int> adj[N];
vector<int> adjT[N];  // reverse,transpose Graph
 
void dfs(int node, vector<int>&vis, stack<int> &st){
    vis[node] = true;
	for(auto nbr: adj[node]){
	    if(!vis[nbr]){
	        dfs(nbr, vis, st);
	    }
	}
 
	st.push(node);  // stores dfs traversal sequence (can be @ start also + vector)
}
 
void revDfs(int node, int ct,  vector<int> &vis){
    vis[node] = ct; 
    for(auto nbr: adjT[node]){
        if(!vis[nbr]){
            revDfs(nbr, ct, vis);
        }
    }
}
 
void kosaraju(int n){  // little modifed 4 this que.
    stack<int> st;
    vector<int> vis(n,0);
	
	 
    for(int i = 0; i < n; i++){
        if(!vis[i]){dfs(i, vis, st);}  // this line is changed from previous wrong submission
    }
 
	fill(all(vis), 0);
 
	int ct = 1;
	while(!st.empty()){
		int top = st.top();
		st.pop();
		if(!vis[top]){
			revDfs(top, ct, vis);
			ct++;
		}
	}
	
	cout<<ct-1<<"\n";
	print(vis);
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

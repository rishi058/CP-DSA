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
SCHOOL DANCE :-
There are n boys and m girls in a school. Next week a school dance will be organized. A
dance pair consists of a boy and a girl, and there are k potential pairs.
Your task is to find out the maximum number of dance pairs and show how this number can
be achieved.

Approach :-
Can also be solved by transforming Ford fulkerson algorithm, but can't understand how 
to print the edges. (refer internet)
 
Kuhn's Algortihm (refer cp-algo):-
Maximum Matching in a Bipartite Graph.
 
*/
 
const int N = 502;
bool vis[N];
int mt[N];      //  contains information about the current matching
vector<int> adj[N];
 
bool try_Kuhns(int node){
    if(vis[node]){return 0;}
    vis[node] = 1;
    for(int child : adj[node]){
        if(!mt[child] || try_Kuhns(mt[child])){
            mt[child] = node;
            return 1;
        }
    }
    return 0;
}
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        int n,m,k;
        cin>>n>>m>>k;
 
        F(0,k,i){
            int u, v;
            cin>>u>>v;
            adj[v].push_back(u);   // Rev
        }
 
        F(1,m+1,i){
            fill(vis+1, vis+m+1, 0);
            try_Kuhns(i);
        }
 
        vector<pair<int,int>> ans;
 
        F(1,n+1,i){
            if(mt[i]){
                ans.push_back({i, mt[i]});
            }
        }
        
        cout<<ans.size()<<"\n";
        for(auto [a,b] : ans){
            cout<<a<<" "<<b<<"\n";
        }
        
    }
 
}

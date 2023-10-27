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
game has n levels, connected by m teleporters, and your task is to get from level 1 to
level n. The game has been designed so that there are no directed cycles in the underlying
raph. In how many ways can you complete the game?
*/

const int N = 1e5+1;
vector<int> adj[N];
vector<int> ways;
 
vector<int> KahnAlgo(int n){  // (n=no. of vertices)
    
    int indegree[n] = {0};
    for(int i=0; i<n; i++){
        for(int x : adj[i]){
            indegree[x]++;
        }
    }
   
    queue<int> q;
    for(int i=0; i<n; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
 
    vector<int> topo;
    while(!q.empty()){
        
        int node = q.front();
        q.pop();
        topo.push_back(node);
 
        for(int x : adj[node]){
            indegree[x]--;
            ways[x] = (ways[x] + ways[node]) % mod;
            if(indegree[x]==0){
                q.push(x);
            }
        }
 
    }
 
    return topo;
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
        }
 
        ways.resize(n,0);
        ways[0] = 1;
        KahnAlgo(n);
 
        cout<<ways[n-1];
        
    }
 
}

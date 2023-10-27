#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(v) v.begin(), v.end()
#define F(a,b,i) for (int i = a; i < b; i++)
#define Rev(a,b,i) for (int i = a; i >= b; i--)
#define RISHI ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
template <typename dStruct>
void print(dStruct& vName){for(auto &it : vName){cout<<it+1<<" ";} cout<<"\n";}
template <typename dStruct>
void print2(dStruct& vName){for(auto &it : vName){cout<<"{"<<it.first<<", "<<it.second<<"} ";} cout<<"\n";}
 
const int mod = 1e9 + 7;
#define inf LONG_LONG_MAX
#define Min LONG_LONG_MIN
 
typedef long double ld;
typedef vector<int> vi;
 
/*---------------------------------------->   MAGIC STARTS   <--------------------------------------------*/

/*
You have to complete n courses. There are m requirements of the form "course a has to be
completed before course b"n. Your task is to find an order in which you can complete the
courses.
*/

vector<int> KahnAlgo(int n, vector<int> adj[]){  // (n=no. of vertices, adjacency mat)
    
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
            if(indegree[x]==0){q.push(x);}
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
        int n,m;
        cin>>n>>m;
 
        vector<int> adj[n];
        F(0,m,i){
            int u,v;
            cin>>u>>v;
            u--; v--;
            adj[u].push_back(v);
        }
 
        vector<int> ans = KahnAlgo(n, adj);
 
        if(ans.size()==n){
            print(ans);
        }
        else{
            cout<<"IMPOSSIBLE\n";
        }
 
    }
 
}

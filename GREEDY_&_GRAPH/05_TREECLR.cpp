#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

/*
for root node :  ways = c;
for child node of root :  ways = c - no_of_child_colored_of_par[c];
for other nodes : ways = c - no_of_child_colored_of_par[c] - 2 { -1 for its own par is colored & -1 for par of parent is colored }
ways[i] = no. of ways of coloring i'th node 
*/

void dfs(ll i, vector<ll> adj[], bool v[], ll parent[], ll child_colored[], ll ways[], ll c){
    v[i]=true;
    
    ll j, l=adj[i].size();
    
    if(i!=1){
        if(parent[i]!=1){
            ways[i]=c-child_colored[parent[i]]-1-1;
            child_colored[parent[i]]++;
        }else{
            ways[i]=c-child_colored[parent[i]]-1;
            child_colored[parent[i]]++;
        }
    }
    
    for(j=0; j<l; j++){
        if(v[adj[i][j]]==false){
            parent[adj[i][j]]=i;
            dfs(adj[i][j], adj, v, parent, child_colored, ways, c);
        }
    }
    
}


int main()
{
    ll n, c, i, j, m;
    
    
        cin>>n>>c;
        
        ll ans=0;
        bool v[n+1];
        ll ways[n+1];
        vector<ll> adj[n+1];
        ll parent[n+1];
        ll child_colored[n+1];
        
        for(i=0; i<=n; i++){
            v[i]=false;
            ways[i]=0;
            parent[i]=0;
            child_colored[i]=0;
        }
        
        m=n-1;
        
        for(;m--;){
            cin>>i>>j;
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
        
        parent[1]=0;
        ways[1]=c;
        
        dfs(1, adj, v, parent, child_colored, ways, c);
        
        ans=1;
        for(i=1; i<=n; i++){
            ans=(ans*ways[i])%mod;
        }
        
        cout<<ans<<"\n";
        
        
    
}
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
Syrjälä's network has n computers and m connections. Your task is to find out if Uolevi can
send a message to Maija, and if it is possible, what is the minimum number of computers on
such a route.
*/

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
            adj[v].push_back(u);
        }
 
        vector<bool> vis(n,0);
        vector<int> par(n,0);
 
 
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        bool ok = 0;
        
        while(!q.empty()){
            int k = q.size();
            int node = q.front();
            q.pop();
 
            for(int child : adj[node]){
                if(!vis[child]){
                    vis[child] = 1;
                    par[child] = node;
                    q.push(child);
                    if(child==n-1){
                        ok = 1;
                        break;
                    }
                }
            }
            
            if(ok){break;}
        }
 
        if(ok){
            vector<int> ans;
            int node = n-1;
            while(node!=0){
                ans.push_back(node+1);
                node = par[node];
            }
            ans.push_back(1);
            reverse(all(ans));
            cout<<ans.size()<<"\n";
            print(ans);
        }
        else{
            cout<<"IMPOSSIBLE\n";
        }
 
    }
 
}

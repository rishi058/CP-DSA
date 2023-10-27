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
Your task is to find a minimum-price flight route from Syrjälä to Metsälä. You have one
discount coupon, using which you can halve the price of any single flight during the route.
However, you can only use the coupon once.
When you use the discount coupon for a flight whose price is c, its price becomes [c/2] (it is
rounded down to an integer).
*/

/*
Every route can be represented as :-
[1]---[A]---[B]---[n], where A,B are direct connected vertices.
let we will always apply copoun on the route [A]--[B].
then ans = min(all_poosible_{A,B});
{A,B} -> can be used from adj list;
dist[1->A] & dist[B->N] is precalculated via djiskstra
*/
 
vector<int> dijkstra(int s, int n, vector<pair<int,int>>adj[]) {
    vector<int> d(n, inf);
 
    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
 
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
 
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }
 
    return d;
}
 
int32_t main()
{
    RISHI
    int T = 1;
    // cin>>T;
    while(T--)
    {
        int n, m;
        cin>>n>>m;
 
        vector<pair<int,int>> adj[n], rev_adj[n];
        F(0,m,i){
            int u, v, wt;
            cin>>u>>v>>wt;
            u--; v--;
            adj[u].push_back({v, wt});
            rev_adj[v].push_back({u, wt});
        }
 
        vector<int> dist0_a = dijkstra(0,n,adj);
        vector<int> distn_b = dijkstra(n-1, n, rev_adj);
 
        int ans = inf;
 
        for(int u=0; u<n; u++){
            for(auto [v,wt] : adj[u]){
                if(dist0_a[u]==inf || distn_b[v]==inf){continue;}
                int temp = dist0_a[u] + wt/2 + distn_b[v];
                ans = min(ans, temp);
            }
        }
 
        cout<<ans<<"\n";
        
    }
 
}
 

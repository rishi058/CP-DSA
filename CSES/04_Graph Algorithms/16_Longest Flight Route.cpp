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
Uolevi has won a contest, and the prize is a free flight trip that can consist of one or more
flights through cities. Of course, Uolevi wants to choose a trip that has as many cities as
possible.
Uolevi wants to fly from Syrjälä to Lehmälä so that he visits the maximum number of cities.
You are given the list of possible flights, and you know that there are no directed cycles in
the flight network.
*/


/*
Define your adjacency list in global -> to pass edge cases;
 
normally in shortest path dijkstra we use ascending data-struct ->
therefore by common sense longest path should use descending data-struct ;
but it gives tle/wrong ans...
*/
 
vector<int> p;
 
vector<pair<int,int>>adj[100005];
 
vector<int> dijkstra(int s, int n) {
    vector<int> d(n,0);
 
    d[s] = 0;
    set<pair<int, int>> q;
 
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        int z = q.begin()->first;
        q.erase(q.begin());
 
 
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
 
            if (d[to] < d[v]+len){
                d[to] = d[v] + len;
                p[to] = v;
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
    while(T--)
    {
        int n,m;
        cin>>n>>m;
 
        F(0,m,i){
            int u,v;
            cin>>u>>v;
            u--; v--;
 
            adj[u].push_back({v,1});
        }
        
        p.resize(n,-1);
        vector<int> dist = dijkstra(0, n);
        
        if(dist[n-1]==0){
            cout<<"IMPOSSIBLE";
        }
        else{
            vector<int> ans;
            int node = n-1;
            while(1){
                ans.push_back(node+1);
                if(node==0){break;}
                node = p[node];
            }
            reverse(all(ans));
            cout<<ans.size()<<"\n";
			print(ans);
        }
    }
 
}

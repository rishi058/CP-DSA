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
You are going to travel from Syrjälä to Lehmälä by plane. You would like to find answers to
the following questions:

what is the minimum price of such a route?
how many minimum-price routes are there? (modulo 109 + 7)
what is the minimum number of flights in a minimum-price route?
what is the maximum number of flights in a minimum-price route?
*/

const int N = 1e5+1;
vector<pair<int,int>> adj[N];
 
vector<int> dist, ways;
vector<int> max_ct, min_ct;
 
void dijkstra(){
    dist[0] = 0;
    ways[0] = 1;
    min_ct[0] = 0;
 
    set<pair<int,int>> st;
    st.insert({0,0});
 
    while(!st.empty()){
        int node = st.begin()->second;
        int d = st.begin()->first;
        st.erase(st.begin());
 
        if(d > dist[node]){continue;}  // imp
 
        for(auto [child, wt] : adj[node]){
 
            if(dist[node]+wt == dist[child]){
                ways[child] = (ways[child] + ways[node]) % mod;
                min_ct[child] = min(min_ct[child], min_ct[node]+1);
                max_ct[child] = max(max_ct[child], max_ct[node]+1);
            }
 
            if(dist[node]+wt < dist[child]){
                dist[child] = dist[node] + wt;
                ways[child] = ways[node];
                min_ct[child] = min_ct[node] + 1;
                max_ct[child] = max_ct[node] + 1;
                st.insert({dist[child], child});
            }
        }
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
 
        F(0,m,i){
            int u,v,wt;
            cin>>u>>v>>wt;
            u--; v--;
            adj[u].push_back({v,wt});
        }
 
        dist.resize(n,inf);
        ways.resize(n,0);
        max_ct.resize(n,0);
        min_ct.resize(n,inf-1);
 
        dijkstra();
 
        cout<<dist[n-1]<<" "<<ways[n-1]<<" "<<min_ct[n-1]<<" "<<max_ct[n-1]<<"\n";
 
    }
 
}
 

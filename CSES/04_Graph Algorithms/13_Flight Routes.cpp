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
Your task is to find the k shortest flight routes from Syrjälä to Metsälä. A route can visit the
same city several times.
Note that there can be several routes with the same price and each of them should be
considered (see the example).
*/

int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        int n,m,k;
        cin>>n>>m>>k;
 
        vector<pair<int,int>> adj[n];
        F(0,m,i){
            int u,v,wt;
            cin>>u>>v>>wt;
            u--; v--;
            adj[u].push_back({v,wt});
        }
 
        vector<int> ct(n,0);
        vector<int> ans;
        multiset<pair<int,int>> q;
        q.insert({0,0});
 
        while(!q.empty()){
            int node_dist = q.begin()->first;
            int node = q.begin()->second;
            q.erase(q.begin());
 
            ct[node]++;
            if(node==(n-1)){
                ans.push_back(node_dist);
                if(ans.size()==k){break;}
            }    
 
            if(ct[node]<=k){
                for(auto [child, child_dist] : adj[node]){
                    q.insert({node_dist+child_dist, child});
                }
            }
 
        }
 
        print(ans);
    }
 
}

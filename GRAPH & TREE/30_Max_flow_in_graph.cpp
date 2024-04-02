#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define aint(v) v.begin(), v.end()
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
 
/*------------------------ 𝑃𝑟𝑎𝑐𝑡𝑖𝑐𝑒 𝑙𝑖𝑘𝑒 𝑦𝑜𝑢'𝑣𝑒 𝑛𝑒𝑣𝑒𝑟 𝑤𝑜𝑛. 𝑃𝑒𝑟𝑓𝑜𝑟𝑚 𝑙𝑖𝑘𝑒 𝑦𝑜𝑢'𝑣𝑒 𝑛𝑒𝑣𝑒𝑟 𝑙𝑜𝑠𝑡. ------------------------*/
 
/*
 
Q.) Download-Speed.

This question is asking us to find the max-flow for the graph.

There are multiple max-flow algorithms,
	1. Dinic's alogrithm (v^2 * e)
	2. Ford-Fulkerson algo (max_flow * e)
	3. Ford + Edmond's karp (v * e^2)
    4. Push Relabel algo
    5. MPM  ....  refer (cp-algo)
 
*/
 
int n;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {        
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, inf});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {             // this is Ford+Edmond, Code taken from cp-algo...
    int flow = 0;
    vector<int> parent(n+1);
    int new_flow;

    while(1){
        new_flow = bfs(s, t, parent);
        if(new_flow==0){break;}

        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}
 
 
int32_t main()
{
	RISHI
	int T = 1;
	while(T--)
	{
		int m;
		cin>>n>>m;

        capacity.resize(n+1, vector<int>(n+1, 0));
        adj.resize(n+1);
 
		F(0,m,i){
			int u, v, wt;
			cin>>u>>v>>wt;
            adj[u].push_back(v);
            adj[v].push_back(u);
            capacity[u][v] += wt;
		}
 
		int ans = maxflow(1, n);
		cout<<ans<<"\n";
	}
 
}

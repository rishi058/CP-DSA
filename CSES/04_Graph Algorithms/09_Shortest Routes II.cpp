#include <bits/stdc++.h>
using namespace std;
 
#define int unsigned long long
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
There are n cities and m roads between them. Your task is to process q queries where you
have to determine the length of the shortest route between two given cities.
*/

const int N = 501;
int dist[N][N];
 
void pre(){     
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i==j){dist[i][j]=0;}
            else {dist[i][j]=inf;}
        }
    }
}
 
int32_t main()
{
    RISHI
    pre();
    int T = 1;
    while(T--)
    {
        int n, m, q;
        cin>>n>>m>>q;
 
        F(0,m,i){
            int u,v,wt;
            cin>>u>>v>>wt;
            dist[u][v] = min(dist[u][v], wt);
            dist[v][u] = min(dist[v][u], wt);
        } 
 
        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
 
        while(q--){
            int u, v;
            cin>>u>>v;
 
            if(dist[u][v]==inf){cout<<"-1\n";}
            else{cout<<dist[u][v]<<"\n";}
        }       
    }
 
}
 

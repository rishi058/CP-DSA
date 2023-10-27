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
You are playing a game consisting of n planets. Each planet has a teleporter to another
planet (or the planet itself).
Your task is to process q queries of the form: when you begin on planet c and travel through
k teleporters, which planet will you reach?
*/

/*
Binary lifting/jumping
Note :- Following is 1 based calculation 
*/
 
const int N = 2e5+1;
const int LogK = 31;
int dp[N][LogK];    // sparse table
 
void pre(int n, vector<int>& par) {
    for (int i = 1; i <= n; i++){dp[i][0] = par[i];}
 
    for(int j = 1; j < LogK; j++){
        for(int i = 1; i <= n; i++){
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }
}
 
int getKthAncestor(int node, int k) {
    for(int i = 0; i < LogK; i++){
        if(k&(1<<i)){
            node = dp[node][i];
        }
    }
    return node;
}
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        int n, q;
        cin>>n>>q;
        vi par(n,0);
 
        F(0,n,i){
            int x; cin>>x;
            par[i+1] = x;        // reversing teleporters to make par arr
        }
 
        pre(n, par);
 
        while(q--)
        {
            int node, k;
            cin>>node>>k;
            cout<<getKthAncestor(node, k)<<"\n";
        }
 
    }
 
}

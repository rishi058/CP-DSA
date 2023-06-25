#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
#define F(a,b,i) for (int i = a; i < b; i++)
#define Rev(a,b,i) for (int i = a; i >= b; i--)
#define RISHI ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define inf LONG_LONG_MAX
#define Min LONG_LONG_MIN

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

vector<vector<int>> dp;

bool isNthBitSet(int& number, int& n){
   int mask = 1 << n;
   return (number & mask) != 0;
}

void flipNthBit(int& number, int n){
   int mask = 1 << n;
   number = number ^ mask;
}

int solve(int start, int par, int mask, vector<vector<int>>& graph){
    if(__builtin_popcount(mask)==graph.size()){
        return 0;
    }
    if(dp[start][mask]!=-1){return dp[start][mask];}
    
    int ans = INT_MAX;
    for(int child : graph[start]){
        if(child==par){continue;}
        int temp=0;
        if(!isNthBitSet(mask, child)){
            flipNthBit(mask, child);
            temp = solve(child, start, mask, graph) + 1;
            flipNthBit(mask, child);
        }
        else{
            temp = solve(child, start, mask, graph) + 1;
        }
        ans = min(ans, temp);
    }

    dp[start][mask] = ans;
}

int shortestPathLength(vector<vector<int>>& graph) {
    int n = graph.size();
    dp.resize(n, vector<int>(1<<n, -1));
    solve(0, -1, 0, graph);
    int vis = (1<<n) - 1;
    int res = INT_MAX;
    for(int i=0; i<n; i++){
        res = min(res, dp[vis][i]);
    }
    return res;
}

int32_t main()
{
    RISHI
    int T; cin>>T;
    while(T--)
    {
        
    }

}



// ███████╗██╗███╗   ██╗██╗███████╗██╗  ██╗    ██╗    ██╗██╗  ██╗ █████╗ ████████╗    ██╗   ██╗ ██████╗ ██╗   ██╗    ███████╗████████╗ █████╗ ██████╗ ████████╗    ██╗
// ██╔════╝██║████╗  ██║██║██╔════╝██║  ██║    ██║    ██║██║  ██║██╔══██╗╚══██╔══╝    ╚██╗ ██╔╝██╔═══██╗██║   ██║    ██╔════╝╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝    ██║
// █████╗  ██║██╔██╗ ██║██║███████╗███████║    ██║ █╗ ██║███████║███████║   ██║        ╚████╔╝ ██║   ██║██║   ██║    ███████╗   ██║   ███████║██████╔╝   ██║       ██║
// ██╔══╝  ██║██║╚██╗██║██║╚════██║██╔══██║    ██║███╗██║██╔══██║██╔══██║   ██║         ╚██╔╝  ██║   ██║██║   ██║    ╚════██║   ██║   ██╔══██║██╔══██╗   ██║       ╚═╝
// ██║     ██║██║ ╚████║██║███████║██║  ██║    ╚███╔███╔╝██║  ██║██║  ██║   ██║          ██║   ╚██████╔╝╚██████╔╝    ███████║   ██║   ██║  ██║██║  ██║   ██║       ██╗
// ╚═╝     ╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝     ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝          ╚═╝    ╚═════╝  ╚═════╝     ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝       ╚═╝
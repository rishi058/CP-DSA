#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define tuple array<int, 3>
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

//!------------------------ Practice like you've never won. Perform like you've never lost. ------------------------

#define tuple array<int, 3>

class Solution {
public:

    unordered_map<int,int> freq;
    unordered_map<tuple, long long> dp;

    long long solve(int idx, vector<int>&v, int prev2, int prev1){
        int n = v.size();
        if(idx>=v.size()){return 0;}
        tuple key = {idx, prev2, prev1};
        if(dp[key]!=0){return dp[key];}

        // take curr_idx [can we take ?]
        bool ok = 1;
        if(v[idx]-prev2<3 || v[idx]-prev1<3){ok=0;}
        long long ans1 = 0;
        if(ok){
            ans1 = solve(idx+1, v, prev1, v[idx]) + v[idx]*freq[v[idx]];
        }

        // not_take
        long long ans2 = solve(idx+1, v, prev2, prev1);

        return dp[key] = max(ans1, ans2);
    }

    long long maximumTotalDamage(vector<int>& power){
        for(int x : power){freq[x]++;}
        vector<int> v;
        for(auto it : freq){v.push_back(it.first);}
        return solve(0, v, -3, -3);
    }
};

int32_t main()
{
    RISHI
    int T = 1;
    cin>>T;
    while(T--)
    {
        vector<int,map<pair<int,int>,long long>> dp;
        dp.resize(5);
        // dp[{1,2,3}] = 1;

        
    }

}


//      ██╗  █████╗  ██╗    ██████╗ ██╗  ██╗ ██████╗  ███████╗ ███████╗   ██████╗   █████╗  ███╗   ███╗
//      ██║ ██╔══██╗ ██║   ██╔════╝ ██║  ██║ ██╔══██╗ ██╔════╝ ██╔════╝   ██╔══██╗ ██╔══██╗ ████╗ ████║
//      ██║ ███████║ ██║   ╚█████╗  ███████║ ██████╔╝ █████╗   █████╗     ██████╔╝ ███████║ ██╔████╔██║
// ██╗  ██║ ██╔══██║ ██║    ╚═══██╗ ██╔══██║ ██╔══██╗ ██╔══╝   ██╔══╝     ██╔══██╗ ██╔══██║ ██║╚██╔╝██║
// ╚█████╔╝ ██║  ██║ ██║   ██████╔╝ ██║  ██║ ██║  ██║ ███████╗ ███████╗   ██║  ██║ ██║  ██║ ██║ ╚═╝ ██║
//  ╚════╝  ╚═╝  ╚═╝ ╚═╝   ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚══════╝ ╚══════╝   ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝     ╚═╝
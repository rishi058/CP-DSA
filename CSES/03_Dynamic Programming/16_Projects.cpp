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
There are n projects you can attend. For each project, you know its starting and ending days
and the amount of money you would get as reward. You can only attend one project during
a day.
What is the maximum amount of money you can earn?
*/

bool cmp(pair<pair<int,int>,int>&a, pair<pair<int,int>,int>&b){
    return a.first.second<b.first.second;
}
 
int32_t main()
{
    RISHI
    int n; cin>>n;
    vector<pair<pair<int,int>,int>> vp;
 
    F(0,n,i){
        int a,b,x;
        cin>>a>>b>>x;
        vp.push_back({{a,b},x});
    }
 
    sort(all(vp), cmp);
 
    vi dp(n,0);
    //DP[i] represents the maximum amount of money that can be earned by attending projects up to the "i"th project.
    dp[0] = vp[0].second;
 
    for(int i=1; i<n; i++){
        int reward = vp[i].second;
        int start = vp[i].first.first;
 
        int lo=0, hi=i-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
 
            int end = vp[mid].first.second;
 
            if(end<start){lo = mid + 1;}
            else{hi = mid-1;}
        }
 
        int prev=0;
        if(lo-1>=0){prev=dp[lo-1];}
        dp[i] = max(reward+prev, dp[i-1]);
    }
    // print(dp);
    cout<<dp[n-1];
}

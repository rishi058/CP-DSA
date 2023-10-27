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
You are given an array of n integers, and your task is to find two values (at distinct positions) whose sum is x.
*/

int32_t main()
{
    RISHI
    
    int n, x;
    cin>>n>>x;
 
    vector<pair<int,int>> vp;
 
    F(0,n,i){
        int x; cin>>x;
        vp.push_back({x,i+1});
    }
 
    sort(all(vp));
 
    int a = 0, b = n-1;
    bool ok = 1;
 
    while(a<b){
        int sum = vp[a].first + vp[b].first;
        if(sum==x){
            cout<<vp[a].second<<" "<<vp[b].second<<"\n";
            ok = 0;
            break;
        }
        if(sum<x){a++;}
        else{b--;}
    }
 
    if(ok){cout<<"IMPOSSIBLE\n";}
 
}

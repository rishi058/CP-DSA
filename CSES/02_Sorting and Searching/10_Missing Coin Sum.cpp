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
You have n coins with positive integer values. What is the smallest sum you cannot create
using a subset of the coins?
*/

int32_t main()
{
    RISHI
    int n; cin>>n;
    
    vi v(n);
    F(0,n,i){cin>>v[i];}
 
    sort(all(v));
    int ans = 1;
 
    F(0,n,i){
        if(v[i]>ans){break;}
        ans += v[i];
    }
 
    cout<<ans;
}
 

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

// Given an array of n integers, your task is to count the number of subarrays having sum x.

int32_t main()
{
    RISHI
    int n, target;
    cin>>n>>target;
 
    map<int,int> prefix; // stores the count of prefix values
    prefix[0] = 1;
 
    int tot_sum = 0, ans = 0;
    F(0,n,i){
        int x; cin>>x;
        tot_sum += x;
        int something = tot_sum - target;
        ans += prefix[something];
        prefix[tot_sum]++;
    }
 
    cout<<ans;
}

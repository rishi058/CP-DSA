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
Given an array of n integers, your task is to count the number of subarrays where the sum
of values is divisible by n.
*/

int32_t main()
{
    RISHI
    int n; cin>>n;
 
    unordered_map<int,int> rem_ct;
    rem_ct[0] = 1;
 
    int prefixSum = 0, ans = 0;
    F(0,n,i){
        int x; cin>>x;
        prefixSum += x;
        prefixSum %= n;
 
        if(prefixSum<0){prefixSum+=n;}
 
        if(rem_ct.find(prefixSum)!=rem_ct.end()){
            ans += rem_ct[prefixSum];
        }
 
        rem_ct[prefixSum]++;
    }
 
    cout<<ans;
}
 

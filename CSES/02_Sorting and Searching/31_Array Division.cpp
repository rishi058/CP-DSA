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
You are given an array containing n positive integers.
Your task is to divide the array into k subarrays so that the maximum sum in a subarray is
as small as possible.
*/


/*
this function will check if it is possible to divide
the arr in <= k parts, such that the max_sum is <= req;
*/
 
bool check(vi &v, int k, int req){ 
    int n = v.size();
    int part_ct = 0, sum = 0;
    F(0,n,i){
        if(sum+v[i]>req){
            part_ct++;
            sum=0;
        }
        sum += v[i];
    }
    if(sum>0){part_ct++;}
    if(part_ct<=k){return 1;}
    return 0;
}
 
int32_t main()
{
    RISHI
    int n, k;
    cin>>n>>k;
 
    int mx = 0, sum = 0;
 
    vi v(n);
    F(0,n,i){cin>>v[i]; sum+=v[i]; mx = max(mx, v[i]);}
 
    int lo=mx, hi=sum, ans;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        bool ok = check(v, k, mid);
        if(ok){
            ans = mid;
            hi = mid-1;
        }
        else{   // indicates ans is too low i.e why parts_ct > k;
            lo = mid+1;
        }
    }
 
    cout<<ans;
}
 

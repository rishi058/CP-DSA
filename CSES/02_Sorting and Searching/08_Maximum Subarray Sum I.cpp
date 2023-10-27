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
Given an array of n integers, your task is to find the maximum sum of values in a
contiguous, nonempty subarray.
*/

int32_t main()
{
    RISHI
    
    int n; cin>>n;
    vi v(n);
    F(0,n,i){cin>>v[i];}
 
    int curr_max = 0, ovrl_max = Min;
 
    F(0,n,i){
        curr_max += v[i];
 
        if(curr_max<0){
            curr_max = 0;
        }
 
        ovrl_max = max(ovrl_max, curr_max);
    }
 
    if(ovrl_max==0){ovrl_max = *max_element(all(v));}
    
    cout<<ovrl_max<<"\n";
}
 

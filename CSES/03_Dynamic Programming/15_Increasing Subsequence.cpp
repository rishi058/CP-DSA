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
You are given an array containing n integers. Your task is to determine the longest
increasing subsequence in the array, i.e., the longest subsequence where every element is
larger than the previous one.
A subsequence is a sequence that can be derived from the array by deleting some elements
without changing the order of the remaining elements.
*/

int lengthOfLIS(vector<int>& nums) {
    vector<int> sub;
    for(int x : nums){
 
        if (sub.empty() || sub.back() < x) {
            sub.push_back(x);
        }
        else{
            auto it = lower_bound(all(sub), x); // Find the index of the first element >= x
            *it = x; // Replace that number with x
        }
 
    }
 
    return sub.size();
}
 
int32_t main()
{
    RISHI
    int n; cin>>n;
    vi v(n);
    F(0,n,i){cin>>v[i];}
    cout<<lengthOfLIS(v);
 
}

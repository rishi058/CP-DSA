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
contiguous subarray with length between a and b.
*/

int32_t main()
{
    RISHI  // SIMULATION
    int n, l, r;
    cin>>n>>l>>r;
    l--; r--;
 
    int sum = 0;
    vi pre(n);  // 1 indexing
 
    F(0,n,i){
        int x; cin>>x;
        sum += x;
        pre[i] = sum;  
    }
    // print(pre);
    multiset<int> st;
 
    F(l,r+1,i){st.insert(pre[i]);}
    // print(st);
    int ans = *st.rbegin();
    int right = r+1, mid = l;
 
    for(int left=0; left+l+1<n; left++){
        st.insert(pre[min(right,n-1)]);
        auto it = st.find(pre[mid]);
        st.erase(it);
        ans = max(ans, *st.rbegin()-pre[left]);
        right++;
        mid++;
        // print(st);
    }
    
    cout<<ans;
 
}

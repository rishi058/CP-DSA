#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
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
You are given an array of n integers. Your task is to calculate the median of each window of
k elements, from left to right.
The median is the middle element when the elements are sorted. If the number of elements
is even, there are two possible medians and we assume that the median is the smaller of
them.
*/

int findMid(oset<pair<int,int>> &st, int mid){
    auto it = *st.find_by_order(mid);
    return it.first;
}
 
int32_t main()
{
    RISHI
    int n, k;
    cin>>n>>k;
 
    vi v(n);
    F(0,n,i){cin>>v[i];}
 
    oset<pair<int,int>> st;
    F(0,k,i){
        st.insert({v[i],i});
    }
 
    int mid = k/2;
    if(k%2==0){mid--;}
 
    int ans = findMid(st, mid);
    cout<<ans<<" ";
 
    F(k, n, i){
        int left = (i-k);
        auto it = st.lower_bound({v[left], -1});
        st.erase(it);
        st.insert({v[i],i});
        ans = findMid(st, mid);
        cout<<ans<<" ";
    }
 
}
 

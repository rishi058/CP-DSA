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
Given n ranges, your task is to count for each range how many other ranges it contains and how many other ranges contain it.

Range [a, b] contains range [c,d] if a <= c and d <= b.
*/

struct range{
    int l,r,id;
    range(int a, int b, int c){
        l = a, r = b, id = c;
    }
};
 
bool cmp(range &a,range &b){
    if(a.l==b.l){return a.r>b.r;}
    else{return a.l<b.l;}
}
 
int32_t main()
{
    RISHI
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n; cin>>n;
 
    vector<range> v;
 
    F(0,n,i){
        int l, r;
        cin>>l>>r;
        v.push_back(range(l,r,i));
    }
 
    sort(all(v), cmp);
 
    vector<int>contained(n); // kisi ke andr ye khud hai ya nhi
    vector<int>contains(n); // kisi ko andr rkha hai ya nhi
 
    oset<pair<int,int>> st;  // {val,kth val} -> technique to store duplicates
    unordered_map<int,int> mp;
 
    F(0,n,i){
        int r = v[i].r;
        mp[r]++;
        st.insert({r, mp[r]});
        int x = st.size() - st.order_of_key({r, 1}) - 1 ;  // count of elements >= x
        contained[v[i].id] = x;
    }
    
    st.clear();
    mp.clear();
 
    Rev(n-1, 0, i){
        int r = v[i].r;
        mp[r]++;
        st.insert({r, mp[r]});
        int x = st.order_of_key({r, mp[r]}) ;  // count of elements <= x
        contains[v[i].id] = x;
    }
 
    print(contains);
    print(contained);
}
 

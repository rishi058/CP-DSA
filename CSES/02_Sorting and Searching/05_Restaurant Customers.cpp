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
You are given the arrival and leaving times of n customers in a restaurant.
What was the maximum number of customers in the restaurant at any time?
*/

int32_t main()
{
    RISHI
    
    int n; cin>>n;
    vector<pair<int,int>> vp;
 
    F(0,n,i){
        int a,b;
        cin>>a>>b;
        vp.push_back({a,b});
    }
 
    sort(all(vp));
 
    int ans = 0;
 
    multiset<int> st;
 
    F(0,n,i){
        int curr_time = vp[i].first;
        st.insert(vp[i].second);
 
        while(!st.empty() && *st.begin()<=curr_time){
            st.erase(st.begin());
        }
 
        ans = max(ans, (int)st.size());
    }
 
    cout<<ans<<"\n";
}

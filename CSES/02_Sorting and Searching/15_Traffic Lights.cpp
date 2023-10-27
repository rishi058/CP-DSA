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
There is a street of length c whose positions are numbered O,1, ..., x. Initially there are no
traffic lights, but n sets of traffic lights are added to the street one after another.

Your task is to calculate the length of the longest passage without traffic lights after each
addition.
*/

int32_t main()
{
    RISHI
    int n, m;
    cin>>n>>m;
 
    set<int> st;
 
    multiset<int, greater<int>> gaps;
    gaps.insert(n);
    
    F(0,m,i){
        int x; cin>>x;
        st.insert(x);
 
        auto it = st.find(x);
        int prev = 0, next = n;
 
        if(it!=st.begin()){auto it1 = it; prev = *(--it1);}
        if(x!=*(--st.end())){next = *(++it);}
 
        int initial_gap = next-prev;
        
        auto itx = gaps.find(initial_gap);
        gaps.erase(itx);
 
        gaps.insert(x-prev);
        gaps.insert(next-x);
        cout<<*gaps.begin()<<" ";
    }
    
}
 

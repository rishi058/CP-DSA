#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(v) v.begin(), v.end()
#define F(a,b,i) for (int i = a; i < b; i++)
#define Rev(a,b,i) for (int i = a; i >= b; i--)
#define RISHI ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
template <typename dStruct>
void print(dStruct& vName){for(auto &it : vName){cout<<it<<" ";} }
template <typename dStruct>
void print2(dStruct& vName){for(auto &it : vName){cout<<"{"<<it.first<<", "<<it.second<<"} ";} cout<<"\n";}
 
const int mod = 1e9 + 7;
#define inf LONG_LONG_MAX
#define Min LONG_LONG_MIN
 
typedef long double ld;
typedef vector<int> vi;
 
/*---------------------------------------->   MAGIC STARTS   <--------------------------------------------*/

/*
You are given a playlist of a radio station since its establishment. The playlist has a total of n songs.

What is the longest sequence of successive songs where each song is unique?
*/

int32_t main()
{
    RISHI
    int n; cin>>n;
    vi v(n);
    F(0,n,i){cin>>v[i];}
 
    if(n==1){cout<<"1"; return 0;}
 
    set<int> st;
    st.insert(v[0]);
 
    int a=0, b=0, ans = 0;
 
    while(1){
        b++;
        if(b==n){break;}
 
        int prev = st.size();
        st.insert(v[b]);
 
        if(prev==(int)st.size()){
            while(1){
                if(v[a]!=v[b]){st.erase(v[a]);}
                if(v[a]==v[b]){a++; break;}
                a++;
            }
        }
 
        ans = max(ans, (int)st.size());
        // print(st);
        // cout<<" : "<<a<<" "<<b<<"\n";
    }
    
    cout<<ans;
}

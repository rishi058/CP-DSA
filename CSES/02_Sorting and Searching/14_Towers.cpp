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
You are given n cubes in a certain order, and your task is to build towers using them.
Whenever two cubes are one on top of the other, the upper cube must be smaller than the
lower cube.

You must process the cubes in the given order. You can always either place the cube on top
of an existing tower, or begin a new tower. What is the minimum possible number of towers?
*/

int32_t main()
{
    RISHI
    int n; cin>>n;
    
    multiset<int> st;
 
    F(0,n,i){
        int x; cin>>x;
 
        auto it = st.upper_bound(x);
        if(it!=st.end()){
            st.erase(it);
            st.insert(x);
        }
        else{st.insert(x);}
    }
 
    cout<<st.size()<<"\n";
}

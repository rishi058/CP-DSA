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
 
#define mod 1e9+7
#define inf LONG_LONG_MAX
#define Min LONG_LONG_MIN
 
typedef long double ld;
typedef vector<int> vi;
 
/*---------------------------------------->   MAGIC STARTS   <--------------------------------------------*/

/*
You are given an array of n integers. You want to modify the array so that it is increasing, i.e., every 
element is at least as large as the previous element.

On each move, you may increase the value of any element by one. What is the minimum number of moves required?
*/

int32_t main()
{
    RISHI
    int n; cin>>n;
    vi v(n);
    F(0,n,i){cin>>v[i];}
 
    int ans = 0;
    F(1,n,i){
        if(v[i]<v[i-1]){
            ans += (v[i-1]-v[i]);
            v[i] = v[i-1];
        }
    }
 
    cout<<ans<<"\n";
}

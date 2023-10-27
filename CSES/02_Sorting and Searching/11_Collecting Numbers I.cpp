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
You are given an array that contains each number between n exactly once. Your task is
to collect the numbers from 1 to n in increasing order.

On each round, you go through the array from left to right and collect as many numbers as
possible. What will be the total number of rounds?
*/

int32_t main()
{
    RISHI
    int n; cin>>n;
 
    vi v(n);
    F(0,n,i){
        int x; cin>>x;
        v[x-1] = i;
    }
 
    int ans = 1;
    F(1,n,i){
        if(v[i]<v[i-1]){ans++;}
    }
 
    cout<<ans;
}
 

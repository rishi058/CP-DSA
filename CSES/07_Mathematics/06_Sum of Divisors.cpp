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

Let c(n) denote the sum of divisors of an integer n. For example, c(12) = 1 + 2+ 3+4 + 6 +12 = 28.
Your task is to calculate the sum E_(i=1...i=n)_[c(i)] modulo 10^9 + 7.

https://www.youtube.com/watch?v=NExDAb-9d9Q&ab_channel=PankajDochania
 
return n*(n+1)/2 % mod
 
*/

int helper(int n){
    int a, b;
    if(n%2){
        a = n;
        b = (n+1)/2;
    }
    else{
        a = n/2;
        b = n+1;
    }
    return ((a%mod) * (b%mod));
}
 
int32_t main()
{
    RISHI
    int n; cin>>n;
 
    int ans = 0;
    for(int i=1; i*i<=n; i++){
        int count = (n/i) - i + 1;
        ans += (count%mod)*i;
        ans %= mod;
        ans += helper(n/i) - helper(i);
        ans += mod;
        ans %= mod;        
    }
 
    cout<<ans;
}
 

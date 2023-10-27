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
There are n children and m apples that will be distributed to them. Your task is to count the
number of ways this can be done.
For example, if n = 3 and m = 2, there are 6 ways: [O, O, 2], [O, 1, 1], [O, 2, [1, O, 1], [1, 1, O] and [2, 0, 0].

Suppose there are n identical objects to be distributed among r distinct bins.
This can be done in precisely in [ (n+r-1)`C,(r-1) ] ways.
*/ 
 
const int N = 2e6+1;
int fac[N];
 
 
int power(int x, int y){
    int res = 1; 
    x = x % mod; 
    while (y){
        if (y & 1){res = (res * x) % mod;}
        y >>= 1; 
        x = (x * x) % mod;
    }
    return res;
}
 
int modInv(int n){
    return power(n, mod - 2);
}
 
int nCrMod(int n, int r){
    // Fermat's Lttle Theorem
    if (n < r){return 0;}
    if (r == 0){return 1;}
    return ( ( ( ( fac[n] * modInv(fac[r] ) ) % mod ) * modInv(fac[n - r]) ) % mod ) % mod;
}
 
void preCompute(){
    fac[0] = 1;
    for(int i=1; i<N; i++){
        fac[i] = (fac[i-1] * i) % mod;
    }
}
 
int32_t main()
{
    RISHI
    preCompute();
    int childs, apples;  // child = distinct bins(r), apples = identical objects(n)
    cin>>childs>>apples;
 
    int up = childs+apples-1;
    int down = childs-1;
 
    int ans = nCrMod(up,down);
    cout<<ans;
 
}

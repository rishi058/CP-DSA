#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ll long long
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
Given a string, your task is to calculate the number of different strings that can be created using its characters.
*/

const int N = 1e6+1;
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
    string s; cin>>s;
    int n = s.size();
 
    int ans = fac[n];
 
    unordered_map<int,int> mp;
    for(char x : s){mp[x]++;}
 
    for(auto it : mp){
        int val = it.second;
        ans = ( ans * modInv(fac[val]) ) % mod;
    }
 
    cout<<ans;
}

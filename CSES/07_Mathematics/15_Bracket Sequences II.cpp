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
Your task is to calculate the number of valid bracket sequences of length n when a prefix of
the sequence is given.
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
 
/*
N'th Catalan Number :-
    [1/(n+1)]*[2n'C(n)]
*/
 
int32_t main()
{
    RISHI
    preCompute();
    int T = 1;
    // cin>>T;
    while(T--)
    {   
        int n; cin>>n;
        string s; cin>>s;
        int k = s.size();
 
        int open = 0, close = 0;
        for(int i=0; i<k; i++){
            if(s[i]=='('){open++;}
            else{close++;}
            if(close>open){break;}
        }
 
        if( (close>open) || n%2 || (open>n/2) ){
            cout<<0;
        }
        else{
            int tot = nCrMod(n-open-close, (n/2)-open);
            int bad = nCrMod(n-open-close, (n/2)-open-1);
 
            int ans = ((tot-bad)%mod + mod)%mod;
            cout<<ans<<"\n";
        }
        
       
    }
 
}

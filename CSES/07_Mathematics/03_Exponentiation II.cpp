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
 
int poww(int a, int b, int mod){
    int ans = 1;
    while(b>0){
        if(b%2==1){
            ans = (ans * a) % mod;
        }
        a = (a*a) % mod;
        b /= 2;
    }
    return ans;
}
 
int32_t main()
{
    RISHI
    int T; cin>>T;
    while(T--)
    {
        int a, b, c;
        cin>>a>>b>>c;
 
        int x = poww(b, c, mod-1);
        int ans = poww(a,x, mod);
        cout<<ans<<"\n";                // (a^b)^c
    }
}
 

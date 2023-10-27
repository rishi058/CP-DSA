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
Your task is to count the number of ways numbers 1, 2, ... , n can be divided into two sets of
equal sum.
For example, if n = 7, there are four solutions:
• {1,3,4,6} and {2, 5, 7}
• {1,2,5,6} and {3, 4, 7}
• {1, 2, 4, 7} and {3, 5, 6}
• {1,6,7} and {2,3,4,5}
*/

int modPow(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (1LL * result * base) % mod;
        }
        base = (1LL * base * base) % mod;
        exp /= 2;
    }
    return result;
}
 
int32_t main()
{
    RISHI
    int n; cin>>n;
    vi v(n+1);
    F(0,n+1,i){v[i]=i;}
 
    int sum = (n*(n+1))/2;
 
    if(sum%2){cout<<0;}
 
    else{
        sum/=2;
        int dp[2][sum+1];
 
        for(int i=0; i<=n; i++){
            for(int j=0; j<=sum; j++){
                if(j==0){dp[i%2][j]=1;}
                else if(i==0){dp[i%2][j]=0;}
                else{
                    if(v[i]<=j){
                        dp[i%2][j] = ( dp[(i-1)%2][j-v[i]] + dp[(i-1)%2][j] ) % mod;
                    }
                    else{
                        dp[i%2][j] = dp[(i-1)%2][j];
                    }
                }
            }
        }
 
        int inverse = modPow(2, mod-2, mod);        // (ans/2) % mod
        int res = (dp[n%2][sum]*inverse)%mod;
 
        cout<<res;
    }
 
}

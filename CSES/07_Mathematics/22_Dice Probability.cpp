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
You throw a dice n times, and every throw produces an outcome between 1 and 6. What is
the probability that the sum of outcomes is between a and b?
*/

ld dp[101][601];  // dp[i][j] = prob of getting sum = "j" in "i" roll.
 
void pre(){
    for(int i=1; i<=6; i++){
        dp[1][i] = 1/(6*1.000000);
    }
 
    for(int i=2; i<=100; i++){
        for(int j=1; j<=(i*6); j++){
 
            for(int k=1; k<=6; k++){
                if(j-k>=0){
                    dp[i][j] += dp[i-1][j-k];
                }
            }
            dp[i][j] = dp[i][j]/(6*1.000000);
        }
    }
}
 
int32_t main()
{
    RISHI
    pre();
    int T = 1;
    while(T--)
    {
        int n, a, b;
        cin>>n>>a>>b;
 
        ld ans = 0;
        for(int i=a; i<=b; i++){
            ans += dp[n][i];
        }
 
        cout<<fixed<<setprecision(6)<<ans;
    }
 
}

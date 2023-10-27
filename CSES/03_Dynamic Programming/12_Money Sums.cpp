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
You have n coins with certain values. Your task is to find all money sums you can create
using these coins.
*/

int32_t main()
{
    RISHI
    // KNAPSACK VARIATION...
 
    int n; cin>>n;
    vi coins(n+1);
    F(0,n,i){cin>>coins[i+1];}
 
    int sum = accumulate(all(coins), 0);
 
    bool dp[n+1][sum+1];
 
    F(0,n+1,i){
        F(0,sum+1, j){
            if(j>0 && i==0 ){dp[i][j]=false;}
            else if(j==0){dp[i][j]=true;}
            
            else{
                if(coins[i]<=j){
                    dp[i][j] = dp[i-1][j-coins[i]] || dp[i-1][j] ;
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
            
        }
    }
 
    vi ans;
    for(int i=1; i<=sum; i++){
        for(int j=1; j<=n; j++){
            if(dp[j][i]==1){ans.push_back(i); break;}
        }
    }
 
    cout<<ans.size()<<"\n";
    print(ans);
}

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*

https://leetcode.com/problems/coin-change/

given an arr having types of coins and a sum.
Find the min no. of coins using which you can achieve the sum..

IF THERE IS NOT ANY COMBINATION OF COINS WHICH SUMS UP TO GIVEN SUM ..
THIS ALGO GIVES INT_MAX-1 value (try ->7,5 sum=16)

*/

int32_t main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vi coins(n+1);

        F(0,n,i){
            cin>>coins[i+1];    // 1 indexed
        }                               
        

        int sum; cin>>sum;

        int dp[n+1][sum+1];

        F(0,n+1,i){
            F(0,sum+1, j){
                if(i==0){dp[i][j]=INT_MAX-1;}
                else if(i==0 && j>0){dp[i][j]=0;}
                else if(i==1){
                    if(j%coins[i]==0){dp[i][j]=j/coins[i];}
                    else{dp[i][j]=INT_MAX-1;}
                }
                
                else{
                    if(coins[i]<=j){
                        dp[i][j] = min(dp[i][j-coins[i]] + 1,  dp[i-1][j]) ;
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
                
            }
        }

        cout<<dp[n][sum]<<"\n";
        F(0,n+1,i){
            F(0,sum+1, j){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
    
    }

}
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*
given an arr having types of coins and a sum.
Find the max no. of ways you can make the sum..
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
                if(j>0 && i==0 ){dp[i][j]=0;}
                else if(j==0){dp[i][j]=1;}
                
                else{
                    if(coins[i]<=j){
                        dp[i][j] = dp[i][j-coins[i]] + dp[i-1][j] ;
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
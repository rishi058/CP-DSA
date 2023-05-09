#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

// https://leetcode.com/problems/coin-change-ii/description/

/*

given an arr having types of coins and a sum. [NOTE :- quantity of each coin is infinity]
Find the total no. of ways in which we can make the sum..

UNBOUNDED + SUBSEQUENCE MIX -->

dp[i][j] = no._of_ways to achieve sum = "j" using coins only ranging from 0 to "i" ;

if(j==0){dp[i][j]=1;}       // if req_sum(i.e "j") = 0, then 1 ans is always possible which is selecting 0 coins. [high priority].

else if(i==0){dp[i][j]=0;}  // if we have 0 coins , then no ans is possible ( except when sum=0 ) , therfore [low_priority]. 

if(coins[i]<=j){                         // if coins[i] is selectable..

    int first_way = dp[i][j-coins[i]] ;  // select coins[i] + no._of_ways to achieve sum = "j-coins[i]" using coins ranging from 0 to "i";
    int second_way = dp[i-1][j]          // don't select coins[i] + no._of_ways to achieve sum = "j" using coins ranging from 0 to "i";
    dp[i][j] = first_wat + second_way ;  // Add to get total no. of ways

}

else{
    dp[i][j] = dp[i-1][j];
}

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
                if(j==0){dp[i][j]=1;}
                else if(i==0){dp[i][j]=0;}
                
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
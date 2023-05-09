#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*
Given a rod nd price of its partial parts, cut rod into a particular way so that price is max..

UNBOUNDED KNAPSACK -->   // [ NOTE :- Always a square matrix ]

wt_arr = len_arr ;
price_arr = price_arr ;
wt_limit  = total_len_of_rod ;

maximize_profit = maximize_profit
 
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
        int len; cin>>len;
        vi length(len+1), price(len+1);

        F(0,len,i){
            length[i+1]=i+1;            // currently you can cut the rod into any desirable len..
        }                               // 1 indexed
        F(0,len,i){
            cin>>price[i+1];
        }

        int limit=len;

        int dp[len+1][limit+1];

        F(0,len+1,i){
            F(0,limit+1, j){
                if(i==0||j==0){
                    dp[i][j]=0;
                }
                else{
                    if(length[i]<=j){
                        dp[i][j]=max(price[i]+dp[i][j-length[i]], dp[i-1][j]);  // this line is chnged from 0/1 knapsack..
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }

        cout<<dp[len][limit]<<"\n";
        F(0,len+1,i){
            F(0,limit+1, j){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
        
    }

}
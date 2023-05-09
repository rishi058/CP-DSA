#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*
Given a weigth arr nd price arr nd wt limit, pik some items so that prfit is max..
NEXT 6 - 12 ARE BASED ON THIS..
*/

/*

Intuition Breakdown -->

dp[i][j] = max_profit if we use products only from 0th to ith index and have wt_limit as j.

NOTE :- 0th index means currently no products.

Therefore, if(i==0 || j==0) { dp[i][j] = 0; }
 
if(wt[i]<=j){  // if the wt of curr_product we're standing on is less than or equal to the curr_wt_limit(i.e j).

int ans1 = va[i] + dp[i-1][j-wt[i]] ;       // if_i_is_selected         [Looking Just 1 Row Up & some columns back]
int ans2 = dp[i-1][j] ;                     // if_not_selected          [Looking Just 1 Row Up]

NOTE :- dp[i-1][j-wt[i]] = max_profit if we use products ranging from 0 to i-1 and has a wt_limit = (j-wt[i]);

dp[i][j] = max(ans1, ans2);

}
else{
    dp[i][j] = dp[i-1][j]                   // if_i_isn't_not_selected  [Looking Just 1 Row Up]
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
        vi wt(n+1), val(n+1);

        F(0,n,i){
            cin>>wt[i+1];
        }                               // 1 indexed
        F(0,n,i){
            cin>>val[i+1];
        }

        int wt_limit; cin>>wt_limit;

        int dp[n+1][wt_limit+1];

        F(0,n+1,i){
            F(0,wt_limit+1, j){
                if(i==0||j==0){
                    dp[i][j]=0;
                }
                else{
                    if(wt[i]<=j){ 
                        dp[i][j]=max(val[i]+dp[i-1][j-wt[i]], dp[i-1][j]);
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }

        cout<<dp[n][wt_limit]<<"\n";
        
        F(0,n+1,i){
            F(0,wt_limit+1, j){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
        

    }

}

/*
1
5
2 4 6 2 3
10 18 30 11 12
9
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*
Given a weigth arr nd price arr, wt limit. pik some items so that prfit is max..
NOTE -> you can pick a single items as many time u want...
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
                        dp[i][j]=max(val[i]+dp[i][j-wt[i]], dp[i-1][j]);  // this line is chnged from 0/1 knapsack..
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
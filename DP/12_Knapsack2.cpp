#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*
In Knapsack When W(limit) value is very high(i.e >1e5) we can't make a 2D array of this size..
So we have to think of difrrent Method......

APPROACH -->
We will conside dp[arr_size][value(V)]  --> Where value = THis value(V) Obtained using minimum weight..

*/

const int value_max = 1e5;
const int n_max = 1000;

int dp[value_max][n_max] ;

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
        F(0,n,i){cin>>wt[i+1];}
        F(0,n,i){cin>>val[i+1];}

        int wt_limit; cin>>wt_limit;

        int value_constraint = accumulate(all(val), 0);

        int dp[n+1][value_constraint+1];

        F(0,n+1,i){
            F(0,value_constraint+1, j){
                if(j==0 || i==0 ){dp[i][j]=0;}
                else if(i==1){dp[i][j]=wt[i];}
                else{
                    if(wt[i-1]>=j){
                        dp[i][j]=min(wt[i]+dp[i-1][j-val[i]], dp[i-1][j]);
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
                
            }
        }

        for(int i=value_constraint; i>0; i--){
            if(dp[n][i]<=wt_limit){
                cout<<i+1<<"\n";
                break;
            }
        }
        F(0,n+1,i){
            F(0,value_constraint+1, j){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }

    }

}
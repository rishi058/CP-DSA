#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*
given an arr nd a sum print count of subet of arr whose sum is equal to given sum;
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
        vi v(n+1);

        F(0,n,i){
            cin>>v[i+1];    // 1 indexed
        }                               
        

        int sum; cin>>sum;

        int dp[n+1][sum+1];

        F(0,n+1,i){
            F(0,sum+1, j){
                if(j>0 && i==0 ){dp[i][j]=0;}
                else if(j==0){dp[i][j]=1;}
                
                else{
                    if(v[i]<=j){
                        dp[i][j] = dp[i-1][j-v[i]] + dp[i-1][j] ;
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
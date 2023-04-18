#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*
given an arr print yes if it is possible to divide it into 2 subset of equal sum...else no..

Can be done usig 1D D.P --> chk gfg....
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

        int sum = 0;
        F(0,n,i){
            cin>>v[i+1];    // 1 indexed
            sum += v[i+1];
        }                               
        
        if(sum%2==1){cout<<"NO\n"; continue;}
        else
        {
            sum /= 2;
            bool dp[n+1][sum+1];

            F(0,n+1,i){
                F(0,sum+1, j){
                    if(j>0 && i==0 ){dp[i][j]=false;}
                    else if(j==0){dp[i][j]=true;}

                    else{
                        if(v[i]<=j){
                            dp[i][j] = dp[i-1][j-v[i]] || dp[i-1][j] ;
                        }
                        else{
                            dp[i][j] = dp[i-1][j];
                        }
                    }

                }
            }

            if(dp[n][sum]){cout<<"YES\n";}
            else{cout<<"NO\n";}

            // F(0,n+1,i){
            //     F(0,sum+1, j){
            //         cout<<dp[i][j]<<" ";
            //     }
            //     cout<<"\n";
            // }
        }     
    
    }

}
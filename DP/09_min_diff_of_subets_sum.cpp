#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*
Given a arr, divide it into 2 parts such that there difference of sum is min..

APPROACH -->

let sum = sum of arr [ s1 , s2 be the subset sum of any two subset of arr.. ]
we have to min = |s2-s1|... s1 be subset sum of 1st sum then sum of the leftover subset is automaticallu sum-s1...
Now we have to min = |sum - 2*s1|,   ---  { [s2 = sum-s1] }
In best case [ min = sum - 2*s1 = 0 ] i.e s1 = sum/2;
so we will use subset sum algo of prev problem to check what is the largest value of s1 which is just less than sum/2..


Can be Done using 1D D.P --> chk gfg...
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
        int sum1,sum=0;
        F(0,n,i){cin>>v[i+1]; sum += v[i+1];}

        sum1 = sum/2;
        bool dp[n+1][sum1 + 1];

        F(0,n+1,i){
            F(0,sum1+1, j){
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

        int ans;
        for(int i=sum1; i>=0; i--){
            if(dp[n][i]==true){
                ans = sum-(2*i);
                break;
            }
        }
        cout<<ans<<"\n";
    }

}
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*

Given an arr you have to assign each element a sign (+ve or -ve) So that the sum of arr is 
equal to the given value...
Find the No. of ways of assigning the sign's...

APPROACH -->
Let the arr be A,B,C,D --> +A-B+C-D || A+B+C-D || -A-B-C+D || etc. comb..
these comb can be converted into (A+B)-(C+D) || (A+B+C) - (D) || (D) - (A+B+C) || etc...
This means we have to divide the arr into 2 parts such that there diff equals given value...
This can be done using prev code...
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
        int n, diff; 
        cin>>n>>diff;
        vi v(n+1);
        int sum=0;
        F(0,n,i){
            cin>>v[i+1];
            sum += v[i+1];
        }

        int x = (diff + sum) / 2;

        int dp[n+1][x+1];

        F(0,n+1,i){
            F(0,x+1, j){
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

        cout<<dp[n][x]<<"\n";

    }

}
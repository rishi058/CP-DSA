#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*
Given an arr nd a diff, in how many ways you can divide the arr into 2 parts such that there diff of sum = given diff...

APPROACH -->

Let s1 and s2 be the 2 req. subet so that s1 - s2 = diff..  --> 1
as we know that s1 + s2 = sum..  -->  2
adding eqn 1 nd 2 ..
we 2*s1 = sum+diff  i.e  s1 = (sum+diff)/2...
So now we have to find the no. of subsets whose sum is this...
We can do this using prev Algo of DP...

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

/*
1
6 3
7 4 1 0 2 5 
ans - 4 [(5,2) (7,4) (4,1) (2+1, 0)]
*/
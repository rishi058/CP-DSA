#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*
We have to find the length of longest subsequence which occurrs more than once 
in the string ..

APProach :-
Note -> LCS of two same str is str itself..
we Have to modify LCS in which we have to add (i!=j) only..
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
        string s1, s2;
        cin>>s1;

        s1 = '0'+s1;
        s2 = s1;

        int n = s1.size(), m = s2.size();

        int dp[n][m];

        F(0,n,i){
            F(0,m,j){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                }
                else if( s1[i]==s2[j] && i!=j ){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        cout<<dp[n-1][m-1]<<"\n";

        F(0,n,i){
            F(0,m,j){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }


    }

}
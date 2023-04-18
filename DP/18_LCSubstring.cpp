#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*
Longest Common Substring -->
This can also be done by another method which is easy to think and hard to implement.
this dp approach is easy to implement.
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
        cin>>s1>>s2;

        s1 = '0'+s1;
        s2 = '0'+s2;

        int n = s1.size(), m = s2.size();

        int dp[n][m];
        int ans=0;

        F(0,n,i){
            F(0,m,j){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                }
                else if(s1[i]==s2[j]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans,dp[i][j]);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }

        cout<<ans<<"\n";
        F(0,n,i){
            F(0,m,j){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }


    }

}
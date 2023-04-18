#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

// print the length of longest decreasing subsequence of given arr...
// [15, 27, 14, 38, 63, 55, 46, 65, 85]  -> 63 55 46

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
        vi v(n);
        F(0,n,i){cin>>v[i];}

        vi dp(n);

        int ans= 0;
    
        F(0,n,i){
            int mx= 0;   

            F(0,i,j){
                if(v[j] > v[i]) {
                    if(dp[j] > mx){mx= dp[j];}
                }
            } 

            dp[i]= mx + 1;
        
            ans = max(ans,dp[i]);
        }
    
        cout<<ans<<"\n";

    }

}
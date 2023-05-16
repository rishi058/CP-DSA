#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

// print the length of longest increasing subsequence of given arr...
// [15, 27, 14, 38, 63, 55, 46, 65, 85]  -> 15 27 38 63/55 65 85 
// 10,9,2,5,3,7,101,18 -> 2,5,7,18

int32_t main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;
    while(t--)
    {
        vi v = {10,9,2,5,3,7,101,18};
        int n = v.size();
        // int n; cin>>n;
        // vi v(n);
        // F(0,n,i){cin>>v[i];}

        vi dp(n);
        int ans= 0;
        F(0,n,i){
            int mx = 0;   
            for(int j=0; j<i; j++){
                if(v[j] < v[i]) {
                   mx = max(mx, dp[j]);
                }
            } 
            dp[i]= mx + 1;
            ans = max(ans,dp[i]);
        }
    
        cout<<ans<<"\n";

//**************    PRINTING LIS   ***********************

        int ind=0;
        F(0,n,i){
            if(dp[i]==ans){ind=i; break;}
        }

        vi vec;
        vec.push_back(v[ind]);
        ans--;
        for(int i=ind-1; i>=0; i--){
            if(v[i]<vec.back() && dp[i]==ans){
                vec.push_back(v[i]);
                ans--;
            }
        }

        reverse(vec.begin(), vec.end());

//*********************************************************

    }

}
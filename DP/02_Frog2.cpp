#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*
N stones are there(1 to n) a frog is initally is at stone 1, he can jump to i+1 or i+2 or i+3 or .... i+k (k is given in que)
every jump costs ( |Hj - Hi| while jumping from i to j) -- (h1,h2...hN will be given)..
find the minimum cost to reach n...
*/

// TC = O(N^2);

int32_t main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;
    while(t--)
    {
        int n, k; cin>>n>>k;
        vi H(n);
        F(0,n,i){cin>>H[i];} 

        vi dp(n, INT_MAX);
        dp[0] = 0;                      // initialization as it will cost 0 to be on 1st stone

        F(1,n,i){
            int y = i - k;
            if(y<0){y=0;}
            F(y,i,j){
                dp[i] = min(dp[i], dp[j]+abs(H[i]-H[j]));
            }
            
        }

        cout<<dp[n-1]<<"\n";
    }

}
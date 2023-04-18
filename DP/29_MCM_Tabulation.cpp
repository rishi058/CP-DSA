#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

int32_t main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin>>t;
	while(t--)
	{
		vi v = { 10, 30, 5, 60  } ;
		int n = v.size() ;

		int dp[n+1][n+1];

		F(1,n+1,i){dp[i][i] = 0;}
		
		
		F(2, n+1, len)        // subsequence lengths
    	{
        	for (int i = 1; i <= n - len + 1; i++)
        	{
        	    int j = i + len - 1;
        	    dp[i][j] = INT_MAX;
	
        	    for (int k = i; j < n && k <= j - 1; k++)
        	    {
        	        int cost = dp[i][k] + dp[k + 1][j] + v[i - 1] * v[k] * v[j];
        	        if (cost < dp[i][j]) {
        	            dp[i][j] = cost;
        	        }
        	    }
        	}
    	}

		cout<< dp[1][n - 1];
		
	}

}
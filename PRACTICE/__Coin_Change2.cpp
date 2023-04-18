#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*

a,b,c = types of coins, 7,5,12
n = sum
We have to find maximum no. of coins to make the sum possible

*/


map<int,int> dp;

int solve(int n, int a, int b, int c){
	if(n==0){return 0;}
	if(n<0){return INT_MIN;}
	if(dp[n]!=0){return dp[n];}

	return dp[n] = 1+max(solve(n-a,a,b,c),max(solve(n-b,a,b,c),solve(n-c,a,b,c))) ;

}

int32_t main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, a, b, c;
	cin>>n>>a>>b>>c;

	cout<<solve(n,a,b,c);
}
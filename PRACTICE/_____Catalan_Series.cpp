#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

int binomialCoeff(int n,int k) 
{ 
    int ans = 1; 
 
    for (int i = 0; i < k; ++i) 
    { 
        ans *= (n - i); 
        ans /= (i + 1); 
    } 
   return ans; 
} 
  

int catalan(int n) 
{ 
    
    int res = binomialCoeff(2*n, n); 
    return res/(n+1); 
}

/*

formula of each catalan n = 2*n^Cn * (1/(n+1)) .

to calculate each catalan O(n) Time is required...

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
		F(0,n,i){
			cout<<catalan(i)<<" ";
		}		
	}

}
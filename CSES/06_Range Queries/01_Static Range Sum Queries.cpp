#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(v) v.begin(), v.end()
#define F(a,b,i) for (int i = a; i < b; i++)
#define Rev(a,b,i) for (int i = a; i >= b; i--)
#define RISHI ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
template <typename dStruct>
void print(dStruct& vName){for(auto &it : vName){cout<<it<<" ";} cout<<"\n";}
template <typename dStruct>
void print2(dStruct& vName){for(auto &it : vName){cout<<"{"<<it.first<<", "<<it.second<<"} ";} cout<<"\n";}
 
const int mod = 1e9 + 7;
#define inf LONG_LONG_MAX
#define Min LONG_LONG_MIN
 
typedef long double ld;
typedef vector<int> vi;
 
//!------------------------ Practice like you've never won. Perform like you've never lost. ------------------------

/*
Given an array of n integers, your task is to process q queries of the form: what is the sum
of values in range [a, b]?
*/

int32_t main()
{
	RISHI
	int T = 1;
	while(T--)
	{
		int n, q;
		cin>>n>>q;
		vi v(n);
		F(0,n,i){cin>>v[i];}
		F(1,n,i){v[i]+=v[i-1];}
 
		while(q--){
			int l, r;
			cin>>l>>r;
			l--; r--;
			int ans;
			if(l==0){ans = v[r];}
			else{ans = v[r]-v[l-1];}
			cout<<ans<<"\n";
		}
	}
 
}
 

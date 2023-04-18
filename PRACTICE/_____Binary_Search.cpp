#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

int binary_search(vi v, int k){
	int n = v.size();
	int low = 0, high = (n-1), ind=-1;

	while(low<=high){
		int mid = (low+high)/2;
		if(v[mid]==k){ind=mid; break;}

		if(v[mid]<k){low=mid+1;}
		if(v[mid]>k){high=mid-1;}
	}

	return ind;

}

int lower_bound(vi v, int k){  // if the element is not present it gives the ind of its next greater element...
	int n = v.size();
	int low = 0, high = (n-1), ind=-1;

	while(low<=high){
		int mid = (low+high)/2;
		if(v[mid]==k){ind=mid; break;}

		if(v[mid]<k){low=mid+1;}
		if(v[mid]>k){high=mid-1;}
	}

	if(ind==-1){
		if(low==n){return -1;}
		else{return low;}
	}

	return ind;

}

int32_t main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin>>t;
	while(t--)
	{
		vi v = {1,3,4,6,9,11,13,21,31};
		cout<<binary_search(v,33)<<"\n";	
		// cout<<lower_bound(v,33);	
	}

}
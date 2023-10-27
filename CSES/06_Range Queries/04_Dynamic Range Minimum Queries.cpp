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
Given an array of n integers, your task is to process q queries of the following types:
1. update the value at position k to u
2. what is the minimum value in range [a, b]?
*/

class segment{
public:
	vector<int> tree;
	int n ;
 
	segment(){}
	segment(vector<int>&arr){build(arr);}
 
	void build(vector<int>&arr){
		n = arr.size();
		tree.resize(2*n, 0);
 
		for(int i=0; i<n; i++){tree[n+i]=arr[i];}
 
		for(int i=(n-1); i>0; --i){
			tree[i] = min(tree[i<<1], tree[i<<1 | 1]);	
		}
	}
 
	// 0 based indexing.
	void updateTreeNode(int p, int value){
		tree[p+n] = value;
		p = p+n;
		for(int i=p; i > 1; i >>= 1){
			tree[i>>1] = min(tree[i] , tree[i^1]);
		}
	}
 
	int query(int l, int r){  // both inclusive
		r++;
		if(l==r){return tree[r+n-1];}
		int res = 1e9+9;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(l&1){res = min(tree[l++],res);}
			if(r&1){res = min(tree[--r],res);}
		}
		return res;
	}
 
};
 
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
		
		segment tree(v);
 
		while(q--){
			int type; cin>>type;
			if(type==1){
				int idx, val;
				cin>>idx>>val;
				idx--;
				tree.updateTreeNode(idx, val);
			}
			else{
				int l, r;
				cin>>l>>r;
				l--; r--;
				int ans = tree.query(l,r);
				cout<<ans<<"\n";
			}
		}
	}
 
}
 

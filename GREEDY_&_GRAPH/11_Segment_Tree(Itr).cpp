#include <bits/stdc++.h>
using namespace std;

/*

BUILD -- O(2*N);
QUERY -- O(LOG(N));
UPDATE -- O(LOG(N));

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Parent(r) =⌊(r−1)/2⌋ if r≠0.

Left child(r) =2r+1 if 2r+1<n.

Right child(r) =2r+2 if 2r+2<n.

Left sibling(r) =r−1 if r is even and r≠0.

Right sibling(r) =r+1 if r is odd and r+1<n.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
RANGE QUERY(ADD X IN RANGE L to R)...

1.) ADD THE CHANGES IN THE ARRAY AND BUILD THE TREE AGAIN..
TC --- O(2*N) + O(R-L+1)

2.) USE UPDATE FUNCTION OVER THE RANGE (R-L+1)..
TC --- O(LOG(N)*(R-L+1))

2nd approach is faster(may be)..
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

TO BUILD **MIN_SEG_TREE** REPLACE MAX BY MIN..

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
			tree[i] = max(tree[i<<1], tree[i<<1 | 1]);	
		}
	}

	// 0 based indexing.
	void updateTreeNode(int p, int value){
		tree[p+n] = value;
		p = p+n;
		for(int i=p; i > 1; i >>= 1){
			tree[i>>1] = max(tree[i] , tree[i^1]);
		}
	}

	int query(int l, int r){  // both inclusive
		r++;
		if(l==r){return tree[r+n-1];}
		int res = 0;                       // update this if you want to modify it to min.
		for(l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(l&1){res = max(tree[l++],res);}
			if(r&1){res = max(tree[--r],res);}
		}
		return res;
	}

};

int main()
{
	
}

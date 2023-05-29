#include <bits/stdc++.h>
using namespace std;

class segement{
public:
	vector<int> tree;
	int n ;

	segement(){}
	segement(vector<int>&arr){build(arr);}

	void build(vector<int>&arr){
		n = arr.size();
		tree.resize(2*n, 0);

		for(int i=0; i<n; i++){tree[n+i]=arr[i];}

		for(int i=(n-1); i>0; --i){
			tree[i] = tree[i<<1] + tree[i<<1 | 1];	
		}
	}

	// 0 based indexing.
	void updateTreeNode(int p, int value){
		tree[p+n] = value;
		p = p+n;
		for(int i=p; i > 1; i >>= 1){
			tree[i>>1] = tree[i] + tree[i^1];
		}
	}

	int query(int l, int r){  // both inclusive
		r++;
		if(l==r){return tree[r+n-1];}
		int res = 0;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(l&1){res += tree[l++];}
			if(r&1){res += tree[--r];}
		}
		return res;
	}

};


int main()
{
	vector<int> v = {1,2,3,4};
	segement tree1(v);

	cout<<tree1.query(0,3)<<"\n";
	tree1.updateTreeNode(2, 5);
	cout<<tree1.query(0,3)<<"\n";
	
}

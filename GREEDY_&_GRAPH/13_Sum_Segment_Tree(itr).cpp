#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
int n; 
int tree[2 * N];

// function to build the tree
void build( int arr[])
{
	// insert leaf nodes in tree
	for (int i=0; i<n; i++)	
		tree[n+i] = arr[i];
	
	// build the tree by calculating parents
	for (int i = n - 1; i > 0; --i)	
		tree[i] = tree[i<<1] + tree[i<<1 | 1];	
}

// function to update a tree node
void updateTreeNode(int p, int value)
{
	// set value at position p
	tree[p+n] = value;
	p = p+n;
	
	// move upward and update parents
	for (int i=p; i > 1; i >>= 1)
		tree[i>>1] = tree[i] + tree[i^1];
}

// function to get sum on interval [l, r) --> { l included / r not included }
int query(int l, int r)
{
	if(l==r){return tree[r+n-1];}
	int res = 0;
	
	for (l += n, r += n; l < r; l >>= 1, r >>= 1)
	{
		if (l&1)
			res += tree[l++];
	
		if (r&1)
			res += tree[--r];
	}
	
	return res;
}

int main()
{
	int a[] = {1, 2, 3, 4, 5};

	n = sizeof(a)/sizeof(a[0]);
	
	build(a);

	for(int i=0; i<=2*n; i++){cout<<tree[i]<<" ";}
    cout<<"\n";
	
	// print the sum in range[l,r) 1 index-based {l->not included}
	cout << query(2, 5)<<endl;
	
	// modify element at 2nd index i.e 3rd element (0 index based)
	updateTreeNode(2, 1);

	for(int i=0; i<=2*n; i++){cout<<tree[i]<<" ";}
    cout<<"\n";
	
	// print the sum in range(1,2) index-based
	cout << query(1, 3)<<endl;

	return 0;
}

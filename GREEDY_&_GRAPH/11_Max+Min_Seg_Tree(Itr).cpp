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

const int N = 100000;
int n;
int tree[2 * N];

void build(int arr[])
{
	for (int i=0; i<n; i++)	
		tree[n+i] = arr[i];
	
	for (int i = n - 1; i > 0; --i)	
		tree[i] = max(tree[i<<1], tree[i<<1 | 1] );	
}

void updateTreeNode(int p, int value)  // 0 indexd
{
	tree[p+n] = value;
	p = p+n;
	
	for (int i=p; i > 1; i >>= 1)
		tree[i>>1] = max(tree[i] , tree[i^1] );
}

int query(int l, int r)  // [l,r) -> 1 indexed
{
    if(l==r){return tree[l+n-1];}
	int res = 0;
	
	for (l += n, r += n; l < r; l >>= 1, r >>= 1)
	{
		if (l&1)
			res = max(tree[l++],res);
	
		if (r&1)
			res = max(tree[--r],res);
	}
	
	return res;
}

int main()
{
	int a[] = {1, 2, 3, 140, 15, 6, 7, 80, 9};

	n = sizeof(a)/sizeof(a[0]);
	
	build(a);

    for(int i=0; i<=2*n; i++){cout<<tree[i]<<" ";}
    cout<<"\n";
	
    // query takes input as [l,r) 1 indexed based {l->not included}
	cout << query(4, 7)<<endl;
	
    //update takes input as 0 indexed.(index, value)...
	updateTreeNode(0, 7);

    for(int i=0; i<=8; i++){cout<<tree[i]<<" ";}
    cout<<"\n";
	
}

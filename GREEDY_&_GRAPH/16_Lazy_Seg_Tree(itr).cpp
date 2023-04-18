#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
int n; 
int tree[2 * N];
int h = sizeof(int) * 8 - __builtin_clz(n);
int d[N];  

void build( int arr[])
{
	for (int i=0; i<n; i++)	
		tree[n+i] = arr[i];
	
	for (int i = n - 1; i > 0; --i)	
		tree[i] = tree[i<<1] + tree[i<<1 | 1];	
}

void updateTreeNode(int p, int value)
{
	tree[p+n] = value;
	p = p+n;
	
	for (int i=p; i > 1; i >>= 1)
		tree[i>>1] = tree[i] + tree[i^1];
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void calc(int p, int k) {
  if (d[p] == 0) tree[p] = tree[p<<1] + tree[p<<1|1];
  else tree[p] = d[p] * k;
}

void apply(int p, int value, int k) {
  tree[p] = value * k;
  if (p < n) d[p] = value;
}


void push(int l, int r) {
  int s = h, k = 1 << (h-1);
  for (l += n, r += n-1; s > 0; --s, k >>= 1)
    for (int i = l >> s; i <= r >> s; ++i) if (d[i] != 0) {
      apply(i<<1, d[i], k);
      apply(i<<1|1, d[i], k);
      d[i] = 0;
    }
}

void modify(int l, int r, int value) {
  if (value == 0) return;
  push(l, l + 1);
  push(r - 1, r);
  bool cl = false, cr = false;
  int k = 1;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) {
    if (cl) calc(l - 1, k);
    if (cr) calc(r, k);
    if (l&1) apply(l++, value, k), cl = true;
    if (r&1) apply(--r, value, k), cr = true;
  }
  for (--l; r > 0; l >>= 1, r >>= 1, k <<= 1) {
    if (cl) calc(l, k);
    if (cr && (!cl || l != r)) calc(r, k);
  }
}
int query(int l, int r) {
  push(l, l + 1);
  push(r - 1, r);
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += tree[l++];
    if (r&1) res += tree[--r];
  }
  return res;
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main()
{
	int a[] = {1, 1, 1, 1, 1};

	n = sizeof(a)/sizeof(a[0]);
	
	build(a);

  cout<<tree[0]<<"\n";

  for(int i=0; i<=2*n; i++){cout<<tree[i]<<" ";}
  cout<<"\n";
	
	// print the sum in range[l,r) 1 index-based {l->not included}
	cout << query(4, 5)<<endl;

  // takes input as { [l,r), value }
  modify(3,5,10);

  for(int i=0; i<=2*n; i++){cout<<d[i]<<" ";}
  cout<<"\n";

	cout << query(0, 4)<<endl;
    
	
	// modify element at 2nd index
	// updateTreeNode(2, 1);
    // for(int i=0; i<=2*n; i++){cout<<tree[i]<<" ";}
    // cout<<"\n";
	
	// print the sum in range(1,2) index-based
	// cout << query(1, 3)<<endl;

	return 0;
}

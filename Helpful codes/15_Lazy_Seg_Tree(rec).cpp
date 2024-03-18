//   https://www.enjoyalgorithms.com/blog/segment-trees-data-structure-part-2

/*
*****************Range Update in Segment Trees..********************

Sometimes problems require updating an interval from l to r instead of a single element. Segment Tree allows
applying modification queries to an entire segment of contiguous elements in O(logn) time.
In the brute force approach, we update all the elements in the range and construct the prefix sum array again,
taking O(n) time. One more solution using segment tree point update is to update all the elements one by one.
The complexity of this approach will be (n) per range update operation, and updating a single element takes
Oflogn) time. Thus, the overall complexity becomes O(nlogn), worse than the prefix sum array approach.

*****************Lazy Propagation in Segment trees..****************
As we know, a node in the segment tree stores a query's value for a range of indexes. If a node range lies within
the range of the update operation, then we need to update all descendants of that node. So, to improve on our
last approach, we become lazy, i.e. we will do work only when required. When there is a need to update an
interval, we will update the node in the segment tree, mark child nodes that require an update and update it
when needed.

With the Lazy propagation idea, we update the node and postpone updates to its children by storing this update
information in a separate array lazyTree[l with the same size as the segment tree. All the elements inside this
array are initially zero, representing that we do not have any updates pending on node i in the segment tree.
Similarly, a non-zero value of lazyTree[i] represents that this much value needs to be updated to node i in the
segment tree before making any query operation..

*/

// Program to show segment tree to demonstrate lazy propagation (range - min)

// https://www.hackerearth.com/problem/algorithm/range-update-range-max-queries/   --> for code testing

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
#define F(a,b,i) for (int i = a; i < b; i++)
#define Rev(a,b,i) for (int i = a; i >= b; i--)
#define RISHI ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define inf LONG_LONG_MAX
#define Min LONG_LONG_MIN

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

class lazySegment {
private:
    int n;
    vector<int> tree;
    vector<int> lazy;
    
    void buildTree(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            buildTree(arr, 2 * node, start, mid);
            buildTree(arr, 2 * node + 1, mid + 1, end);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }
    
    void updateLazy(int node, int start, int end, int l, int r, int val) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        
        if (start > end || start > r || end < l)
            return;
        
        if (start >= l && end <= r) {
            tree[node] += val;
            if (start != end) {
                lazy[2 * node] += val;
                lazy[2 * node + 1] += val;
            }
            return;
        }
        
        int mid = (start + end) / 2;
        updateLazy(2 * node, start, mid, l, r, val);
        updateLazy(2 * node + 1, mid + 1, end, l, r, val);
        
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
    
    int queryMin(int node, int start, int end, int l, int r) {
        if (start > end || start > r || end < l)
            return INT_MAX;
        
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        
        if (start >= l && end <= r)
            return tree[node];
        
        int mid = (start + end) / 2;
        int left = queryMin(2 * node, start, mid, l, r);
        int right = queryMin(2 * node + 1, mid + 1, end, l, r);
        
        return min(left, right);
    }
    
public:
    lazySegment(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        lazy.resize(4 * n);
        buildTree(arr, 1, 0, n - 1);
    }
    
    void rangeUpdate(int l, int r, int val) {
        updateLazy(1, 0, n - 1, l, r, val);
    }
    
    int queryMin(int l, int r) {
        return queryMin(1, 0, n - 1, l, r);
    }
};

int32_t main()
{
    RISHI
    int n, q;
	cin>>n>>q;

	vi v(n);
	F(0,n,i){cin>>v[i];}

	lazySegment tree(v);

	while(q--)
	{
		char ch; cin>>ch;
		if(ch=='q'){
			int l, r;
			cin>>l>>r;
			l--; r--;
			cout<<tree.queryMin(l,r)<<"\n";
		}
		else{
			int l, r, x;
			cin>>l>>r>>x;
			l--; r--;
			tree.rangeUpdate(l,r,x);
		}
	}

}



// ███████╗██╗███╗   ██╗██╗███████╗██╗  ██╗    ██╗    ██╗██╗  ██╗ █████╗ ████████╗    ██╗   ██╗ ██████╗ ██╗   ██╗    ███████╗████████╗ █████╗ ██████╗ ████████╗    ██╗
// ██╔════╝██║████╗  ██║██║██╔════╝██║  ██║    ██║    ██║██║  ██║██╔══██╗╚══██╔══╝    ╚██╗ ██╔╝██╔═══██╗██║   ██║    ██╔════╝╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝    ██║
// █████╗  ██║██╔██╗ ██║██║███████╗███████║    ██║ █╗ ██║███████║███████║   ██║        ╚████╔╝ ██║   ██║██║   ██║    ███████╗   ██║   ███████║██████╔╝   ██║       ██║
// ██╔══╝  ██║██║╚██╗██║██║╚════██║██╔══██║    ██║███╗██║██╔══██║██╔══██║   ██║         ╚██╔╝  ██║   ██║██║   ██║    ╚════██║   ██║   ██╔══██║██╔══██╗   ██║       ╚═╝
// ██║     ██║██║ ╚████║██║███████║██║  ██║    ╚███╔███╔╝██║  ██║██║  ██║   ██║          ██║   ╚██████╔╝╚██████╔╝    ███████║   ██║   ██║  ██║██║  ██║   ██║       ██╗
// ╚═╝     ╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝     ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝          ╚═╝    ╚═════╝  ╚═════╝     ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝       ╚═╝


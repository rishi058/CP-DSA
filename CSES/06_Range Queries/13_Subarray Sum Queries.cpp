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

// There is an array consisting of n integers. Some values of the array will be updated, and after each update, your task is to report the maximum subarray sum in the array.

/*
Max subarray Sum Queries :-
--> Dividing problems into sub-problem.
 
--> If we know the ans of 2 child problems i.e  
    max-subarray-sum[l,k] & max-subarray-sum[k+1,r]   // k is anything b/w l & r.
    How can we deduce the ans for max-subarray-sum[l,r]
 
--> from observation we can have 3 cases :-
    1. ans exists in completly in left subarray.
    2. ans exists in completly in right subarray.
    3. ans occupies in a segment including from both side.
 
3. We can find the ans of 3rd case by adding max-Suffix-Sum of left segment &
   max-prefix-sum of right segment.
 
Therfore -> ans[l,r] = max( ans(l,k), ans(k+1,r), MSS[l,k]+MPS[k+1,r] )
*/
 
struct Node {
    int mxSubsum, mxSuffix, mxPrefix, sum;
    Node() : mxSubsum(0), mxSuffix(0), mxPrefix(0), sum(0) {}
    Node(int mxSub, int mxS, int mxP, int s) : mxSubsum(mxSub), mxSuffix(mxS), mxPrefix(mxP), sum(s) {}
 
    Node operator+(Node b) {
		return {max(max(mxSubsum, b.mxSubsum), mxPrefix + b.mxSuffix),
		        max(mxSuffix, sum + b.mxSuffix), max(b.mxPrefix, mxPrefix + b.sum),
		        sum + b.sum};
	}
};
 
class Segment {
public:
    vector<Node> tree;
    int n;
 
    void buildTree(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node].mxSubsum = max(0LL, arr[start]);
            tree[node].mxPrefix = max(0LL, arr[start]);
            tree[node].mxSuffix = max(0LL, arr[start]);
            tree[node].sum = arr[start];
        }else {
            int mid = (start + end) / 2;
            buildTree(arr, 2 * node, start, mid);
            buildTree(arr, 2 * node + 1, mid + 1, end);
 
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
 
    void updateHelper(int node, int start, int end, int index, int val) {
        if (start == end) {
            tree[node].sum = val;
            tree[node].mxSubsum = max(0LL, val);
            tree[node].mxPrefix = max(0LL, val);
            tree[node].mxSuffix = max(0LL, val);
        } else {
            int mid = (start + end) / 2;
            if (index <= mid) {
                updateHelper(2 * node, start, mid, index, val);
            } else {
                updateHelper(2 * node + 1, mid + 1, end, index, val);
            }
 
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
 
    Node queryHelper(int node, int start, int end, int left, int right) {
        if (start > right || end < left) {
            return Node(0, 0, 0, 0);
        } else if (start >= left && end <= right) {
            return tree[node];
        } else {
            int mid = (start + end) / 2;
            Node L = queryHelper(2 * node, start, mid, left, right);
            Node R = queryHelper(2 * node + 1, mid + 1, end, left, right);
            return L+R;
        }
    }
 
    Segment() {}
    Segment(vector<int>& arr) { initialize(arr); }
 
    void initialize(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n, Node(0, 0, 0, 0));
        buildTree(arr, 1, 0, n - 1);
    }
 
    void update(int index, int val) {
        updateHelper(1, 0, n - 1, index, val);
    }
 
    int query(int left, int right) {
        return queryHelper(1, 0, n - 1, left, right).mxSubsum;
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
 
		vi arr(n);
		F(0,n,i){cin>>arr[i];}
 
        Segment maxSubarrayTree(arr);
        
		while(q--){
			int idx, val;
            cin>>idx>>val;
            idx--;
 
			maxSubarrayTree.update(idx, val);
			int ans = maxSubarrayTree.query(0,n-1);
			cout<<ans<<"\n";
			
		}
		
	}
 
}

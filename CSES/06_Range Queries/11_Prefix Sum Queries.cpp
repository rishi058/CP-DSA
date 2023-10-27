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
Subarray Sum Queries :-

Given an array o n integers, your tas is to
1. update the value at position k to u
2. what is the maximum prefix sum in range [a,b]?

*/
 
struct Node{
    int mxPrefix, sum;
    Node() : mxPrefix(0), sum(0) {} 
    Node(int mx, int s) : mxPrefix(mx), sum(s) {}
};
 
class Segment {
public:
    vector<Node> tree;
    int n;
 
    void buildTree(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node].mxPrefix = max(0LL, arr[start]);    // point to note
            tree[node].sum = arr[start];
        }
        else {
            int mid = (start + end) / 2;
            buildTree(arr, 2 * node, start, mid);
            buildTree(arr, 2 * node + 1, mid + 1, end);
 
            tree[node].sum = tree[2*node].sum + tree[2*node + 1].sum;   // normal sum eqaution 
            tree[node].mxPrefix = max(tree[2 * node].mxPrefix, tree[2*node].sum + tree[2 * node + 1].mxPrefix);   // derived eqaution
        }
    }
 
    void updateHelper(int node, int start, int end, int index, int val) {
        if (start == end) {
            tree[node].sum = val;
            tree[node].mxPrefix = max(0LL, val);   // point to note..
        } else {
            int mid = (start + end) / 2;
            if (index <= mid) {
                updateHelper(2 * node, start, mid, index, val);
            } else {
                updateHelper(2 * node + 1, mid + 1, end, index, val);
            }
            
            tree[node].sum = tree[2*node].sum + tree[2*node + 1].sum;   // normal sum eqaution 
            tree[node].mxPrefix = max(tree[2 * node].mxPrefix, tree[2*node].sum + tree[2 * node + 1].mxPrefix);   // derived eqaution
        }
    }
 
    Node queryHelper(int node, int start, int end, int left, int right) {   // {maxPrefix, sum}
        if (start > right || end < left) {
            return Node(0,0);
        }
        else if (start >= left && end <= right) {
            return tree[node];
        }
        else {
            int mid = (start + end) / 2;
            Node L = queryHelper(2 * node, start, mid, left, right);
            Node R = queryHelper(2 * node + 1, mid + 1, end, left, right);
            int maxPrefix = max(L.mxPrefix, L.sum + R.mxPrefix);
            return Node(maxPrefix, L.sum+R.sum);           // {maxPrefix, tot-range-sum}
        }
    }
 
    Segment(){}
    Segment(vector<int>& arr) {initialize(arr);}
 
    void initialize(vector<int>&arr){
        n = arr.size();
        tree.resize(4*n, Node(0,0));
        buildTree(arr, 1, 0, n - 1);
    }
 
    void update(int index, int val) {
        updateHelper(1, 0, n - 1, index, val);
    }
 
    int query(int left, int right) {
        return queryHelper(1, 0, n - 1, left, right).mxPrefix;
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
 
        Segment maxPrefixTree(arr);
 
		while(q--){
			int type; cin>>type;
			if(type==1){
				int idx, val;
				cin>>idx>>val;
				idx--;
 
				maxPrefixTree.update(idx, val);
			}
			else{
				int l, r;
				cin>>l>>r;
				l--; r--;
				
				int ans = maxPrefixTree.query(l,r);
				cout<<ans<<"\n";
			}
		}
		
	}
 
}

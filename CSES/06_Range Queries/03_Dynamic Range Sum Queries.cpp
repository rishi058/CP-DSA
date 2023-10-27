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
2. what is the sum of values in range [a, b]?
*/

class Segment {
private:
    vector<int> tree;
    int n;
 
    void buildTree(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        }
        else {
            int mid = (start + end) / 2;
            buildTree(arr, 2 * node, start, mid);
            buildTree(arr, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
 
    void updateHelper(int node, int start, int end, int index, int val) {
        if (start == end) {
            tree[node] = val;
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
 
    int queryHelper(int node, int start, int end, int left, int right) {
        if (start > right || end < left) {
            return 0;
        }
        else if (start >= left && end <= right) {
            return tree[node];
        }
        else {
            int mid = (start + end) / 2;
            int leftSum = queryHelper(2 * node, start, mid, left, right);
            int rightSum = queryHelper(2 * node + 1, mid + 1, end, left, right);
            return leftSum + rightSum;
        }
    }
 
public:
    Segment(){}
    Segment(vector<int>& arr) {initialize(arr);}
 
    void initialize(vector<int>&arr){
        n = arr.size();
        tree.resize(4 * n);
        buildTree(arr, 1, 0, n - 1);
    }
 
    void update(int index, int val) {
        updateHelper(1, 0, n - 1, index, val);
    }
 
    int query(int left, int right) {
        return queryHelper(1, 0, n - 1, left, right);
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
		
		Segment tree(v);
 
		while(q--){
			int type; cin>>type;
			if(type==1){
				int idx, val;
				cin>>idx>>val;
				idx--;
				tree.update(idx, val);
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
 

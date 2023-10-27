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
There are n hotels on a street. For each hotel you know the number of free rooms. Your task
is to assign hotel rooms for groups of tourists. All members of a group want to stay in the
same hotel.
The groups will come to you one after another, and you know for each group the number of
rooms it requires. You always assign a group to the first hotel having enough rooms. After
this, the number of free rooms in the hotel decreases.


Hotel Queries :-
Note :- We can do normal lower_bound because we have to utilize hotels from L to R.
1. Construct a Range Max Queries Segment Tree.
2. with this we can find 1st hotel where we can put the guests using binary search.
3. check (1, mid) -> (1, mid/2) or (mid/2, N)
 
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
            int x; cin>>x;
 
            int lo=0, hi=n-1;
            while(lo<=hi){
                int mid = (lo+hi)/2;
 
                int mx = tree.query(lo,mid);
 
                if(mx<x){
                    lo = mid+1;
                }
                if(mx>=x){
                    hi = mid-1;
                }
            }
 
            int val = tree.query(lo,lo);
            if(val<x){cout<<"0 ";}
            else{
                int dif = val - x;
                cout<<lo+1<<" ";
                tree.updateTreeNode(lo, dif);
            }
 
        }
        
    }
 
}
 

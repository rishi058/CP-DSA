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
You are given a list consisting of n integers. Your task is to remove elements from the list at
given positions, and report the removed elements.

List Removal :-
1. Simulating what it says is simple but will give tle.
2. 
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
			tree[i] = tree[i<<1] + tree[i<<1 | 1];	
		}
	}
 
	// 0 based indeidxing.
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
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        int n; cin>>n;
 
        vi v(n);
        F(0,n,i){cin>>v[i];}
 
        vector<int> present(n,1);  // keep track of elements_presents of a range.
        segment tree(present);
        
        F(0,n,i){
            int idx; cin>>idx;
 
            int lo=0, hi=n-1, res;
            while(lo<=hi){
                int mid = (lo+hi)/2;
 
                int ele_pres = tree.query(0,mid);
 
                if(ele_pres==idx){
                    tree.updateTreeNode(mid, 0);
                    res = v[mid];
                    hi = mid-1;
                }
                if(ele_pres<idx){
                    lo = mid+1;
                }
                else if(ele_pres>idx){
                    hi = mid-1;
                }
 
            }
            
            cout<<res<<" ";           
        }
        
    }
 
}
 
 
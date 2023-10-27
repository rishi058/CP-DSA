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
Pizzeria Queries :-
There are n buildings on a street, numbered 1, 2, . ..,n. Each building has a pizzeria and an
apartment.
The pizza price in building k is Pk. If you order a pizza from building a to building b, its price
(with delivery) is pa + la — bl.
Your task is to process two types of queries:
1. The pizza price in building k becomes c.
2. You are in building k and want to order a pizza. What is the minimum price?


Normal Approach O(n):
    cost[i] = min(p[j] + |i-j|)  {j -> (1 to n)}
 
To improve it (split the formula):
    cost[i] = min( min(p[j1] + i-j1) , min(p[j2] + j2-i ) )             {j1<i && j2>i}
 
    cost[i] = min( min( (p[j1]-j1) + i) , min( (p[j2]+j2) -i ) )        {j1<i && j2>i}
 
We can build 2 segment range min trees for (p[i]-i) &&  (p[i]+i) .
 
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
			tree[i] = min(tree[i<<1], tree[i<<1 | 1]);	
		}
	}
 
	// 0 based indexing.
	void updateTreeNode(int p, int value){
		tree[p+n] = value;
		p = p+n;
		for(int i=p; i > 1; i >>= 1){
			tree[i>>1] = min(tree[i] , tree[i^1]);
		}
	}
 
	int query(int l, int r){  // both inclusive
		r++;
		if(l==r){return tree[r+n-1];}
		int res = inf;                       // update this if you want to modify it to min.
		for(l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(l&1){res = min(tree[l++],res);}
			if(r&1){res = min(tree[--r],res);}
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
 
        vi a(n), b(n);
        F(0,n,i){
            a[i] = v[i]-i;
            b[i] = v[i]+i;
        }
 
        segment tree1(a), tree2(b);
 
        while(q--){
            int type; cin>>type;
            if(type==1){
                int idx, val;
                cin>>idx>>val;
                idx--;
 
                tree1.updateTreeNode(idx, val-idx);
                tree2.updateTreeNode(idx, val+idx);
            }
            else{
                int idx; cin>>idx;
                idx--;
                int ans1 = tree1.query(0, idx) + idx;
                int ans2 = tree2.query(idx+1, n-1) - idx;
                cout<<min(ans1,ans2)<<"\n";
            }
        }
        
    }
 
}
 

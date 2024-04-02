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
CSES : Subtree Queries.

You are given a rooted tree consisting of n nodes. The nodes are numbered 1, 2, , n, and
node 1 is the root. Each node has a value.
Your task is to process following types of queries:
1. change the value of node s to c
2. calculate the sum of values in the subtree of node s
*/

/*
 
Subtree Queries :-
A tree is given where each node is assigned with a value.
2 types of Queris -> 1 : [s, x -> change the value of node s to x]
                     2 : [s    -> find the sum of value of subtree 's']
 
Approach :-
1. Flatten the tree (using dfs) [known as Eular Tour]
2. Entire subtree of a particular node forms a contiguous subarray in the resultant flattened array.
3. Subarray can be found in range {idx[node], idx[node] + node_ct[node]}  {node_ct = no. of nodes in subtree 's'}
4. rearrange the value-arr a/c to flatten_arr,
5. make a segment_tree/fenwick-tree of this value array.
6. when query = 1, find the idx[s] and update its value.
7. when query = 2, return the range-sum of idx[s], idx[s]+node_ct[x]
 
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
 
	// 0 based indexing.
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
 
 
const int N = 2e5+2;
int values[N], nodes_ct[N], idx[N];
vector<int> adj[N];
 
void dfs(int node, int par, vi &res){
    idx[node] = res.size();
    res.push_back(values[node]);
    int nd = 1;
    for(int child : adj[node]){
        if(child!=par){
            dfs(child, node, res);
            nd += nodes_ct[child];
        }
    }
    nodes_ct[node] = nd;
}
 
 
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        int n, q;
        cin>>n>>q;
 
        F(1,n+1,i){cin>>values[i];}
 
        F(1,n,i){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vi res;
        res.push_back(0);
        dfs(1, 0, res);

        // for(int i=1; i<=n; i++){
        //     cout<<idx[i]<<" ";
        // }
        // cout<<"\n";

        // for(int i=1; i<=n; i++){
        //     cout<<nodes_ct[i]<<" ";
        // }
        // cout<<"\n";

        // print(res);
 
        segment tree(res);
 
        while(q--){
            int type; cin>>type;
            if(type==1){
                int node, val;
                cin>>node>>val;
 
                int ind = idx[node];
                tree.updateTreeNode(ind, val);
            }
            else{
                int node; cin>>node;
                int l = idx[node];
                int r = l + nodes_ct[node] - 1;
                int ans = tree.query(l,r);
                cout<<ans<<"\n";
            }
        }
        
    }
 
}

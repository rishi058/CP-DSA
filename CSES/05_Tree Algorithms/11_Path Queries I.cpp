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
You are given a rooted tree consisting of n nodes. The nodes are numbered 1, 2
node 1 is the root. Each node has a value.
Your task is to process following types of queries:
1. change the value of node s to x
2. calculate the sum of values on the path from the root to node s

Path Queries -->
1. Path queries question can be done using Heavy-light-Decomposition(HLD).
2. Previous submission was based on HLD.
3. But Sum queries can be done in a more easier wasy i.e using eular tour (flattening tree).
4. After Building Type-II eular tour we can see that evey node appears 2-times (1 @ entry, 2 @ exit)
 
4. Note :- a path from root(1) to (x) -> is represeted as a subarray {entry[1], entry[x]} = {0, idx_of_entry[x]}
                                      -> but some nodes are occuring twice in b/w subarr, which are not the part of path..
 
5. We can create a val_arr -> where @ entry we put +ve val_of_node AND @ exit we put -ve.
   then prefix_sum[1,..entry[node]] will give the sum of the path from 1 to node.
   [to update the val_arr, and do query_sum we will build seg-tree of val_arr].
 
------------------------------------------------->    <--------------------------------------------------
 
WHAT IF WE HAVE TO FIND PATH SUM FROM ('u' -> 'v') :-
--> 2 appraoches are there. 
 
I.   ans(u,v) = path_sum(1, u) + path_sum(1,v) - 2*path_sum(LCA(u,v)).
 
II. if( lca(u,v) == u ) { ans = subarr_sum(entry[a], entry[b]) }
    else { ans = subarr_sum(entry[a], entry[b])  + val_of_lca(a,b) + val_of(a); }
 
    Note :- +val_of(a) bcz in this subarray exit[a] is also present therfore exit[a] will nullify entry[a] 
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
 
 
//***********************************************************************************************************
 
const int N = 2e5+2;
vector<int> adj[N];
int value[N], entry_idx[N], exit_idx[N];
vector<int> eular_tour, val_arr;
 
void dfs(int node, vector<bool>&vis){
    vis[node] = 1;
    entry_idx[node] = eular_tour.size();
    eular_tour.push_back(node);
    val_arr.push_back(value[node]);
 
    for(int child : adj[node]){
        if(!vis[child]){
            dfs(child, vis);
        }
    }   
 
    exit_idx[node] = eular_tour.size();
    eular_tour.push_back(node);
    val_arr.push_back(-value[node]);
}
 
 
//***********************************************************************************************************
 
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        int n, q;
        cin>>n>>q;
 
        F(1,n+1,i){cin>>value[i];}
 
        F(1,n,i){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
 
        vector<bool> vis(n+1,0);
        dfs(1, vis);
        // print(eular_tour);
        // print(val_arr);
        // F(1,n+1,i){cout<<entry_idx[i]<<" ";}
        // F(1,n+1,i){cout<<exit_idx[i]<<" ";}
 
        segment tree(val_arr);
 
        while(q--){
            int type; cin>>type;
 
            if(type==1){     // update
                int node, new_val;
                cin>>node>>new_val;
 
                tree.updateTreeNode(entry_idx[node], new_val);
                tree.updateTreeNode(exit_idx[node], -new_val);
            }
            else{           // queries 
                int node;
                cin>>node;
 
                int ans = tree.query(0, entry_idx[node]);
                cout<<ans<<"\n";
            }
        }
        
    }
 
}

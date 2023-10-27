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
You are given a tree consisting of n nodes. The nodes are numbered 1, 2, ... , n. Each node
has a value.
Your task is to process following types of queries:
1. change the value of node s to c
2. find the maximum value on the path between nodes a and b.

Path Queries II -->
1. Path queries question can be done using Heavy-light-Decomposition(HLD).
2. In HLD, tree is flatten by cutting the tree into multiple chains & putting the chains in linear order.
3. Query -> to traverse the path from 'u' to 'v' 
            a.) we jump to chain head of 'u' & 'v'.
            b.) and them jump to another chain connected to it (i.e a more havy chain).
            c.) perform (a), (b) until 'u' & 'v' are on same chain.
            d.) if 'u' and 'v' are on same chain, perform range query b/w 'u' & 'v'.
            e.) Note :- [we had flatten the tree such that each chain are ordered linearly]
            f.) Note :- [while preforming (a), we are also keeping track of 'max' of that chain 
                        too bcz that is also the part of the path...]
*/
 
//***********************************************************************************************************
 
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
		int res = 0;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(l&1){res = max(tree[l++],res);}
			if(r&1){res = max(tree[--r],res);}
		}
		return res;
	}
 
};
 
//***********************************************************************************************************
 
vector<int> parent, depth, heavy, head, pos;
int cur_pos;           // A counter used to keep track of the current position while decomposing the tree.
 
int dfs(int v, vector<int> adj[]) {
    int size = 1;
    int max_c_size = 0;
    for (int c : adj[v]) {
        if (c != parent[v]) {
            parent[c] = v, depth[c] = depth[v] + 1;
            int c_size = dfs(c, adj);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, heavy[v] = c;
        }
    }
    return size;
}
 
void decompose(int v, int h, vector<int> adj[]) {
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h, adj);
    for (int c : adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c, adj);
    }
}
 
void init(vector<int> adj[], int n) {
    parent = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);     // heavy[i] = heavy_child_of_node_i, {i.e node with more subtree_size}
    head = vector<int>(n);          // An array storing the head of each chain (path) in the decomposition.
    pos = vector<int>(n);           // An array storing the position of each node in the flattened chain.
    cur_pos = 1;
 
    dfs(1, adj);
    decompose(1, 1, adj);
}
 
int query(int a, int b, segment &tree) {
    // Initialize the result to 0.
    int res = 0;
    
    // Traverse the tree while both 'a' and 'b' are not in the same heavy path.
    for (; head[a] != head[b]; b = parent[head[b]]) {
        // If 'a' is deeper in the tree than 'b', swap them.
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        
        // Query the segment tree for the maximum value on the heavy path
        // between 'pos[head[b]]' and 'pos[b]', and update 'res' with the maximum value.
        int cur_heavy_path_max =  tree.query(pos[head[b]], pos[b]); 
        res = max(res, cur_heavy_path_max);
    }
    
    // If 'a' is deeper in the tree than 'b', swap them.
    if (depth[a] > depth[b])
        swap(a, b);
    
    // Query the segment tree for the maximum value on the final heavy path
    // between 'pos[a]' and 'pos[b]', and update 'res' with the maximum value.
    int last_heavy_path_max = tree.query(pos[a], pos[b]);
    res = max(res, last_heavy_path_max);
    
    // Return the maximum value found during the traversal.
    return res;
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
 
        vector<int> val(n+1,0);
        F(1,n+1,i){cin>>val[i];}
 
        vector<int> adj[n+1];
        F(1,n,i){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
 
        init(adj, n+1);   // generating HLD of tree.
 
        // print(pos);
        vi flatten_tree(n+1,0);
        vi flatten_val(n+1, 0);
 
        F(1,n+1,i){
            flatten_tree[pos[i]] = i;
        }
 
        F(1,n+1,i){
            flatten_val[i] = val[flatten_tree[i]];
        }
 
        segment tree(flatten_val);   // building seg tree..
 
        while(q--){
            int type; cin>>type;
 
            if(type==1){     // update
                int node, new_val;
                cin>>node>>new_val;
 
                tree.updateTreeNode(pos[node], new_val);
            }
            else{           // queries 
                int node1, node2;
                cin>>node1>>node2;
 
                int ans = query(node1, node2, tree);
                cout<<ans<<" ";
            }
        }
        
    }
 
}

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
 
/*---------------------------------------->   MAGIC STARTS   <--------------------------------------------*/

/*
There are n cities and initially no roads between them. However, every day a new road will
be constructed, and there will be a total of m roads.
A component is a group of cities where there is a route between any two cities using the
roads. After each day, your task is to find the number of components and the size of the
largest component.
*/

class DSU{
public :
    vector<int> parent, Size;
    
    void makeNodes(int sz){ // this func create n independent nodes automatically
        for(int i=0; i<sz; i++){ make(i); }
    }
 
    DSU(int sz){
        parent.resize(sz, 0);   // use 0, for avoiding bugs.
        Size.resize(sz, 0);
    }
 
    void make(int v){ parent[v] = v; Size[v] = 1; } 
 
    int find(int v){                                      // Recursion 
        if(v==parent[v]) { return v; }
        else { return parent[v] = find(parent[v]); }     // path compression 
    }
 
    void UnionBySize(int a, int b){   
        a = find(a); b = find(b);
        if( a!=b ){   
            if(Size[a] < Size[b]) { swap(a,b); }      
            parent[b] = a; Size[a] += Size[b];
        }
    }
};
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        int n, m;
        cin>>n>>m;
 
		DSU tree(n);
		tree.makeNodes(n);
 
		int components = n;
		int max_size = 1;
 
		F(0,m,i){
			int u, v;
			cin>>u>>v;
			u--; v--;
 
			if(tree.find(u)!=tree.find(v)){
				components--;
			}
			
			tree.UnionBySize(u, v);
			int par = tree.find(u);
			max_size = max(max_size, tree.Size[par]);
			cout<<components<<" "<<max_size<<"\n";
		}
 
    }
 
}
 

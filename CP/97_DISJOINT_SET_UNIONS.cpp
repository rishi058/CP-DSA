#include <bits/stdc++.h>
using namespace std;

/*
DSU is user-defined data structure..
It is used to make group of trees..

It has 3 function..
1. Make     -->     it is used to make a independent node..
2. find     -->     it gives you the root of a node -- (parent of the group) -- (topmost element)
3. Union    -->     it is used to form union i.e join(a,b) = group containg node a 
                    nd another group cantaining node b join's together to form 1 group.


the tree formed using DSU is directed towards parent of the group..
this tree have some diffrent properties w.r.t to normal tree..

it is a simpler than dfs, so some question's of dfs can also be solved using DSU.
but questions having a properties like DSU trees will only be solved by DSU..

find the no. of connected components --> (can be solved by both DSU & DFS)
find presense of a cycle -->  (can be solved by both DSU & DFS)

NOTE :-  
1. find func is diff from LCA of DFS..
2. Union(a,b) ->   if no. of nodes of parent of a == no. of nodes of parent of b.
                   then compare a,b. if a<b then overall parent after union is parent of a.

                   if no. of nodes of parent of a < no. of nodes of parent of b.
                   then overall parent after union is parent of b 

3. Types of union ->
     a.)   weighted union / union by size (mention above)
     b.)   union by rank.

In union by rank, each node in the tree has an associated rank, 
When performing a union operation, the tree with the smaller rank is merged into the tree with the larger rank.
By default, rank is the HEIGHT of the tree.
It's ensure that when we combine two trees, we try to keep the overall depth of the resulting tree small.

NOTE :- HEIGHT of tree and SIZE(total no. of node) of tree aren't same thing.

*/

const int N = 1e5+7;
int parent[N];
int Size[N];
int Rank[N];


void make(int v){                   
    parent[v] = v;
    Size[v] = 1;
    Rank[v] = 0;
}

int find(int v){                                      // Recursion 
    if(v==parent[v]) { return v; }
    else { return parent[v] = find(parent[v]); }     // path compression 
}

void UnionBySize(int a, int b){   
    a = find(a);
    b = find(b);
    if( a!=b ){   
        if(Size[a] < Size[b]) { swap(a,b); }      // logic for weighted union..
        parent[b] = a;                            // we may also use if else statement..
        Size[a] += Size[b];
    }
}

void UnionByRank(int a, int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        if(Rank[a]<Rank[b]){
            parent[a] = b;
        }
        else if(Rank[a]>Rank[b]){
            parent[b] = a;
        }
        else{
            parent[b] = a;
            Rank[a]++;
        }
    }
}


int main()
{
    int n,k; cin>>n>>k;
    for(int i=1; i<=n; i++){
        make(i);
    }
    while(k--)
    {
        int u,v;
        cin>>u>>v;
        UnionBySize(u, v);
    }

    int connected_comp = 0;
    // connected components = no. of nodes whose parent node is himself.
    for(int i=1; i<=n; i++){
        if(find(i)==i){connected_comp++;}
    }
    cout<<connected_comp;

}
/*
INPUT -->
8 5  (N= No. of comp.) (e = no. of edges)
1 2
2 3
2 4
3 5
6 7 
*/
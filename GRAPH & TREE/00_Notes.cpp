#include <bits/stdc++.h>
using namespace std;
 
 /*
    Graph representation -->
    1. Matrix
    2. List --> Array of Vectors, Vector of Vectors  (commons)

    Traversal --> (algorithm+Approach)
    1. DFS  (Depth First Search)
    2. BFS  (Breadth First Search)
    These are the most common algo used in graph and trees.

    Imp. Algo-->
    1. Djikstra.
    2. Bellman-Ford.
    ****************Extra's************
    3. Disjoint Set Union.
    4. Minimum Spanning Tree.
    5. Directed Acyclic Graph.
    6. Topological Sort

    Graph Terminologies -->  (graph is also known as forest)

    Acyclic Graph -->  a directed Graph where cycle appears but dont have actual cycle bcz dir. of edges dont form cycles.
    Cyclic Graph  -->  a graph containing cycle.
    Trees         -->  graph which dont have any cycles. 

    1. Vertices(v) And Edges(e)   {v = no. of elements} {e = no. of lines}  (e = v-1 , in trees)
    2. Undirected and Directed Graphs.
    3. Connected Components.   (group of components connected with edges)
    4. Strongly Connected Components. 
    5. Height And Depth in a tree. (no. of edges in b/w)  (height of a vertex in dist of it from bottom-most vertex) (depth of vertex is dist of it from its root)
    6. Root/Child/Parent/ Leaf Nodes in a Tree(i.e last node)

    4. strongly connented components.(in directed graphs)
    if 3 comp. a,b,c such that we can go a-->b-->c || b-->a-->c || etc, all comb.
    then these 3 are 1 strongly connected component. e.g-->a,b,c are in cycle
    a single comp. is 1 strongly conn. cmp. if its neighbour are useless.

    7.LCA (first common parent).


    //! ********GRAPH REPRESENTATION*************

    1. Adjency method
    2. list - array of vectors   (most common)

    In adjency(i.e matrix method):-
    --> we have to make a matrix of rows/columns equal or greater than constraints of magnitude(i.e value of vertices);
    --> in this, -ve value can't be used as a magnitude, bcz rows/column depict values..
    --> element of the matrix depict weight of edges (0 if no edge exists)

    --> it is suitable for both directed and undirected graph

    --> Generally input is given by :-  (eg of undirected with cycle graph :-)
    6 9      // n,m  = no. of vertices, edges__;
    1 3     // connecting components given __
    1 5    //weights if given :-
    3 5   6
    3 5   4
    3 4   3
    3 6
    3 2
    2 6
    4 6
    5 6

    lect. - 83

    */

   
/*
************GRAPH REPRESENTATION*************
2. List method

-->array of vectors  ( vector <int> graph[N] )    N = 1e7;

-->size of array is the constraint given (i.e max value of vertex)
-->let x is a value so x^th element of array will have a vector of (value of vertices) to which it is connected to..

--> if wieght is given  ( vector<pair<int>> graph[N] )   inserting weight with each vertex.

--> Generally input is given by :-  (undirected Eg-->)
6 9            // n,m = no. of verices, edges :-
1 3 4
1 5 3
3 5 2
3 4 7
3 6 8
3 2 9
2 6 1
4 6 2
5 6 3
*/

const int N = 1e5+5;
vector<pair<int,int>> graph[N];    // all ele of array is 0 initially..

int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int v1, v2, wt;
        cin>>v1>>v2>>wt;

        graph[v1].push_back({v2, wt});  // vetex v1 is conn. to v2    
        graph[v2].push_back({v1, wt});  //vertex v2 is conn. to v1   --since undirected--
    }
}
/*

in adjacency matrix method , it is easy to find whether 2 vertices is conn. or not
or what is weight of edge b/w them -->   by accessing graph[i][j] directly..  O(1)_

in list it is not possible--> we have to use loop-->

for(int chilld : graph[i]){
    if(child==j){
        cout<<"connected ";
    }
}

or

for( pair <int,int> chilld : graph[i] ){
    if(child.first==j){
        cout<<"connected ";
        cout<<"weight : "<<child.second ;
    }
}

*/
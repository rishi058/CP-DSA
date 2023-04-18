#include<bits/stdc++.h>
using namespace std;

long long n;
/*


arr[itr] - 1 = total no. of children of itr which is colored already. (for root node)
arr[itr] - 2 = total no. of children of itr which is colored already.

for root node :  ways = c;
for child node of root :  ways = c - no_of_child_colored_of_par[c];
for other nodes : ways = c - no_of_child_colored_of_par[c] - 2 { -1 for its own par is colored & -1 for par of parent is colored }
ways[i] = no. of ways of coloring i'th node.

This modified code gives ans when in question no two adjacent vertex is of same color is given..
Ans will be greater than ans of prev problem..
ans = c * (c-1)^m  {m = no. of vertices - 1}

*/

void dfs(vector <long long> tree[],long long arr[],long long node,long long c,long long &ans)
{
    long long tmp=0;                
    for(auto itr : tree[node])      // iterating through all connected nodes of node..
    {
        if(arr[itr]>0)   // if itr is parent of the node (only 1 time its true)
        {
            tmp=arr[itr];       // storing the value of colored brothers..
            //arr[itr]++;         // ++ for indicating that one more children of itr is colored now.
            //arr[node]++;        // ++ the node to indicate that the parent of its parent is also colored..  
        }
    }
    
    arr[node]++; // for making the node as visited..

    ans=((ans*(c-tmp))%(1000000007));

    cout<<node+1<<" "<<ans<<"\n";
    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<"\n\n";

    for(auto itr : tree[node])
    {
        if(arr[itr]==0){
            dfs(tree,arr,itr,c,ans);
        }
    }
}
int main()
{
    long long c,ans=1;
    cin>>n>>c;              // n == no. of edges + 1, c = colors
    long long arr[n]={0};
    vector <long long> tree[n];
    for(long long a=0;a<n-1;a++)
    {
        long long x,y;
        cin>>x>>y;
        tree[x-1].push_back(y-1);
        tree[y-1].push_back(x-1);
    }
    dfs(tree,arr,0,c,ans);
    // cout<<ans;
    // ans = c * (c-1)^m  {m = no. of vertices - 1}
    return 0;
}
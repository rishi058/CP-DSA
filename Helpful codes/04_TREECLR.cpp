#include<bits/stdc++.h>
using namespace std;

long long n;

/*
arr[itr] - 1 = total no. of children of itr which is colored already. (for root node)
arr[itr] - 2 = total no. of children of itr which is colored already.

Number of ways to paint a tree of N nodes with K distinct colors with given conditions.
return the number of ways of painting the tree such that any two nodes that are at distance 1 or 2 are painted in different colors. 
*/

void dfs(vector <long long> tree[],long long arr[],long long node,long long c,long long &ans)
{
    long long tmp=0;                
    for(auto itr : tree[node])      // iterating through all connected nodes of node..
    {
        if(arr[itr]>0)   // if itr is parent of the node (only 1 time its true)
        {
            tmp=arr[itr];       // storing the value of colored brothers..
            arr[itr]++;         // ++ for indicating that one more children of itr is colored now.
            arr[node]++;        // ++ the node to indicate that the parent of its parent is also colored..  
        }
    }
    
    arr[node]++; // for making the node as visited..

    ans=((ans*(c-tmp))%(1000000007));

    // cout<<node+1<<" "<<ans<<"\n";
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
    cin>>n>>c;
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
    return 0;
}
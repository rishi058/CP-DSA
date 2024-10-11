#include <bits/stdc++.h>
using namespace std;

int solution(vector<int>arr){
    int ans=INT_MIN;
    int result=-1;
    vector<int>weight(arr.size(),0);
    for(int i=0;i<arr.size();i++){
        int source=i;
        int dest=arr[i];
        if(dest!=-1){
            weight[dest]+=source;
            if(ans<=weight[dest]){
                ans=max(ans,weight[dest]);
                result=dest;
            }
            
        }
    }
    if(ans!=INT_MIN)
        return result;
    return -1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> edges(n);
    for (int i = 0; i < n; i++)
        cin >> edges[i];

    int c1, c2;
    cin >> c1 >> c2;

    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        if (edges[i] == -1)
            continue;
        adj[i].push_back(edges[i]);
    }
    vector<int> v1 = shortPath(adj, c1, n);
    vector<int> v2 = shortPath(adj, c2, n);

    int mn = INT_MAX, node = -1;
    for (int i = 0; i < n; i++)
    {
        if (v1[i] == INT_MAX || v2[i] == INT_MAX)
            continue;
        if (v1[i] + v2[i] < mn)
        {
            mn = v1[i] + v2[i];
            node = i;
        }
    }
    cout << node << endl;
    return 0;
}
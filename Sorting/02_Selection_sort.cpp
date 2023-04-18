#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*

The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) 
from unsorted part and putting it at the beginning. 
The algorithm maintains two subarrays in a given array.

*/

void selectionSort(vi &arr)
{

    int min_idx, n=arr.size();
 
    // One by one move boundary of
    // unsorted subarray
    F(0,n,i){
       
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        F(i+1, n, j){
            if (arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        
 
        // Swap the found minimum element
        // with the first element
        if(min_idx!=i){
            swap(arr[min_idx], arr[i]);
        }
    }
}

// Note => In Insertion sort we swap the sub array one step ahead , but here we swap the two elements.. 

int32_t main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;
    while(t--)
    {
        vi array = {10, 3, 21, 9, 12, 31} ;
        selectionSort(array);
        for(int x : array){
            cout<<x<<" ";
        }
    }

}
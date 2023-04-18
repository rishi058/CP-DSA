#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(vi &arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(vi &arr)
{
   int n = arr.size();
   int curr_size;  // For current size of subarrays to be merged
                   // curr_size varies from 1 to n/2
   int left_start; // For picking starting index of left subarray
                   // to be merged
  
   // Merge subarrays in bottom up manner.  First merge subarrays of
   // size 1 to create sorted subarrays of size 2, then merge subarrays
   // of size 2 to create sorted subarrays of size 4, and so on.
   for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
   {
       // Pick starting point of different subarrays of current size
       for (left_start=0; left_start<n-1; left_start += 2*curr_size)
       {
           // Find ending point of left subarray. mid+1 is starting 
           // point of right
           int mid = min(left_start + curr_size - 1, n-1);
  
           int right_end = min(left_start + 2*curr_size - 1, n-1);
  
           // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
           merge(arr, left_start, mid, right_end);
       }
   }
}

void mergeSort2(vi &arr, int begin, int end)
{
    if (begin >= end)
        return; // Returns recursively
 
    auto mid = begin + (end - begin) / 2;
    mergeSort2(arr, begin, mid);
    mergeSort2(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}
 

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
        mergeSort(array);
        for(int x : array){
            cout<<x<<" ";
        }
    }

}

// VISUAL OF HOW A ARRAY IS SPLIT IN MERGE ALGO...
// THIS WILL HELP IN CP QUESTIONS.. 


void print(vi &v, int l, int m, int r){
    // if(r-l<=2){return;}
    F(l,m,i){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    F(m,r,i){
        cout<<v[i]<<" ";
    }
    cout<<"\n";

}

void merge2(vi &arr, int begin, int end)
{
    if (begin>=end || end-begin<=2){return;}
 
    int mid = begin + (end - begin) / 2;
    // cout<<"\nmid-"<<mid<<" \n";
    print(arr, begin, mid, end);
    merge2(arr, begin, mid);
    merge2(arr, mid, end);

    // merge(arr, begin, mid, end);
}

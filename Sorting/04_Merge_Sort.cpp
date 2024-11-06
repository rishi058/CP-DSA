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
void merge(vi &arr, int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1, n2 = r - m;
 
    int L[n1], R[n2];
 
    for(i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }

    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
    }
 
    i = 0, j = 0, k = l; 
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k++] = L[i++];
        }
        else{arr[k++] = R[j++];}
    }
 
    while(i < n1){arr[k++] = L[i++];}
 
    while(j < n2){arr[k++] = R[j++];}
}
 
void mergeSort(vi &arr, int begin, int end){
    if(begin >= end){return;}

    int mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
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
        mergeSort(array, 0, array.size()-1);
        for(int x : array){
            cout<<x<<" ";
        }
    }

}

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*

Step 1 :
Choose any pos for pivot(1st, mid, last), count the no. of element samller than equal to pivot (ct).
Then the sorted pos of pivot will be { starting(i.e now 0) + ct } , now swap arr[0] and arr[strt+ct]. 
i.e Place pivot at its correct position

Step 2:
Now We have to move all elements smaller than equal to pivot on LHS and all elemnet Greater than Pivot on RHS.
To do so, take two pointers, compare arr[i] && arr[j]..
if arr[i]>Pivot && arr[j]<Pivot the swap(arr[i],arr[j]) i++, j--,
else i++ or j-- on based condn...

Step 3:
When we have done this First time on Whole array. Now do the same thing on LHS & RHS arr..
recusively..

NOTE :
! Worst Case is O(n^2), when pivot is the Largest element always (i.e sorting a DESC list & pivot is 1st pos)
! Best, Avg is O(nlogn)
*/


//! FIRST EASY PARTITION TYPE (2 PASS)

// int partition(vector<int>&v, int lo, int hi){
//     int pivot = v[lo], ctMini = 0;// Take 1st element as pivot.
//     for(int i=lo+1; i<=hi; i++){
//         if(v[i]<=pivot){ctMini++;}// elements equal to pivot should be left of pivot 
//     }
//     int pivotIdx = lo + ctMini;
//     swap(v[lo], v[pivotIdx]);     // placing pivot at its correct position.
//     while(lo<pivotIdx && hi>pivotIdx){
//         while(lo<pivotIdx && v[lo]<=pivot){
//             lo++;
//         }
//         while(hi>pivotIdx && v[hi]>pivot){
//             hi--;
//         }
//         if(lo<pivotIdx && hi>pivotIdx){
//             swap(v[lo], v[hi]);
//         }
//     }
//     return pivotIdx;
// }

//! Little Optimized partion (1 Pass)

// NOTE : a is compared with hi & b is compared with lo;

int partition(vector<int>&v, int lo, int hi) {
    int pivot = v[lo], a = lo, b = hi; 
    while(a < b){
        while(a<=hi && v[a]<=pivot){   
            a++;
        }
        while(b>=lo && v[b]>pivot){   
            b--;
        }
        if(a<b){swap(v[a], v[b]);}
    }
    swap(v[lo], v[b]);
    return b; 
}

void quickSort(vi &arr, int low, int high){
    if(low>=high){return;}
    
    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
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
        vi array = {5,2,3,1} ;
        quickSort(array, 0, 3);
        for(int x : array){
            cout<<x<<" ";
        }

    }

}
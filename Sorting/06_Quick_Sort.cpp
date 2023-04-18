#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*

Step 1 -> First Take any Element(let arr[0]) as pivot, count in arr no. of element samller than arr[0],
          then the sorted pos of arr[0] is { starting(i.e now 0) + ct } , now swap arr[0] and arr[strt+ct]..

Step 2 -> Now We have to move all elements smaller than pivot on LHS and all elemnet Greater than Pivot on RHS.
            To do so, take two point i=(starting), j = (ending). compare arr[i] && arr[j]..
            if arr[i]>Pivot && arr[j]<Pivot the swap(arr[i],arr[j]) i++, j--,
            else i++ or j-- on based condn...

Step 3 -> When we have done this First time on Whole array. Now do the same thing on LHS & RHS arr..
            recusively or iteratively..

*/

int partition(vi &arr, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = arr[low];
    while (i < j)
    {
        while (pivot >= arr[i])
            i++;
        while (pivot < arr[j])
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
  
void quickSort(vi &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
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
        quickSort(array, 0, 5);
        for(int x : array){
            cout<<x<<" ";
        }

    }

}
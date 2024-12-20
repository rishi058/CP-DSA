#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a, b, i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in the wrong order.
This algorithm is not suitable for large data sets as its average and worst-case time complexity is quite high.

sorting is visible from right to left
i.e largest elements is placed at the end of the array & so on...

Step 1 -> arr[0], arr[1] ko compare karo agar ascending hai (i.e arr[0]<arr[1]) to rehne do nhi to swap kardo..

Srep 2 -> next element ko iterate karo, each (N) TC k baad last (n) element sort ho jata hai automatically...
         T.C == (n*N).
*/


void bubbleSort(vi &arr){
    int n = arr.size();

    for(int i=0; i<n-1; i++){
        // Last/right-side 'i' elements are already in place
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int32_t main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        vi array = {10, 3, 21, 9, 12, 1};
        bubbleSort(array);
        for (int x : array)
        {
            cout << x << " ";
        }
    }
}
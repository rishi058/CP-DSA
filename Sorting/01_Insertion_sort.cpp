#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*

Insertion Sort, 
Selection Sort,
Bubble Sort, 
Merge Sort, 
Heap Sort, 
QuickSort, 
Radix Sort, 
Counting Sort, 
Bucket Sort, 
ShellSort, 
Comb Sort

Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands. 
The array is virtually split into a sorted and an unsorted part. 
Values from the unsorted part are picked and placed at the correct position in the sorted part.

What are the Boundary Cases of Insertion Sort algorithm?
Insertion sort takes maximum time to sort if elements are sorted in reverse order. And it takes minimum time (Order of n) when elements are already sorted. 

What are the Algorithmic Paradigm of Insertion Sort algorithm?
Insertion Sort algorithm follows incremental approach.

Is Insertion Sort an in-place sorting algorithm?
Yes, insertion sort is an in-place sorting algorithm.

Is Insertion Sort a stable algorithm?
Yes, insertion sort is a stable sorting algorithm.

When is the Insertion Sort algorithm used?
Insertion sort is used when number of elements is small. It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.

*/


/*

Step 1 :

arr[0] | arr[1], arr[2], ...., arr[n-1]

1. Currently arr is divided into 2 parts [left(1 element) & right(n-1 elements)], left is sorted & right isn't.

2. Store the first element of Right part in 'key' var.

3. We have to insert 'key' in its correct position in left part such that the size of left part inc by 1.

4. We can do it in two ways : 

let 'j' = idx of 'key';

4.1. By swaping adjacent elements till if(arr[j-1] > arr[j]){swap(arr[j-1], arr[j]); j--;}

4.2. Traditional Card Sorting : Shift elements which are left side of key by 1 pos, which are greater than key.
     if(arr[j-1] > key){arr[j] = arr[j-1]; j--;}



*/

void print(int i, vector<int> &v){
    for(int k=0; k<v.size(); k++){
        cout<<v[k]<<", ";
        if(i==k){cout<<"| ";}
    }
    cout<<"\n";
}

void insertionSort(vi &arr){
    int n = arr.size();

    for(int i=1; i<n; i++){
        //! Multiple SWAPING  
        // int j = i;
        // while(j>0 && (arr[j-1]>arr[j])){
        //     swap(arr[j-1], arr[j]);
        //     j--;
        // }

        //! Card Sorting (Shifting)
        int key = arr[i], j = i;
        while(j>0 && arr[j-1]>key) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = key;

        // print(i, arr);
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
        vi array = {4,6,5,1,3,2} ;
        insertionSort(array);
        for(int x : array){
            cout<<x<<" ";
        }
    }

}
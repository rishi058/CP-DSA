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

Step 1 -> First element ko key maanlo fir , second pos se iterate karo and ""usse"" chota element dhundo,
            agar usse chota element mil gya to - jitna bhi element key se lekar chota element k piche tak hai.
            sabko pos +1 kardo fir key element ka space khali ho jayega to usme chota element ko daaldo..

Step 2 -> Usi loop ko continue karo, agar koi element key se chota ho to uske key k piche(LhS) k saare element
            se compare karo aur Sahi Pos me usko insert kardo By swap all elements infont of that sahi element..
            SAHI element == jo element founded se bhi chota ho !..

*/
void insertionSort(vi &arr)
{
    int key, j, n = arr.size();
    F(1,n,i){
        key = arr[i];
        j = i - 1;
        /* Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
        insertionSort(array);
        for(int x : array){
            cout<<x<<" ";
        }
    }

}
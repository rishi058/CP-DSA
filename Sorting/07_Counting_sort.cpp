#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;

//------------------------------------------------------

/*
Counting Sort:-

Pros:
-Time Complexity O(N)
- Compareless sorting

Cons:
-Limited Usage i.e for ""int""
-Memory Consuption

Uses:
- Sort numbers
- find counts of letter from string
- remove duplicate from string
- find kth smallest or biggest element from array within O(N) time.


Counting sort is efficient if the range of input data is not significantly greater than the number of objects to be sorted. 
Consider the situation where the input sequence is between range 1 to 10K and the data is 10, 5, 10K, 5K. 

It is not a comparison-based sorting. Its running time complexity is O(n) with space proportional to the range of data. 
Counting sort is able to achieve this because we are making assumptions about the data we are sorting.
It is often used as a sub-routine to another sorting algorithm like radix sort. 
Counting sort uses partial hashing to count the occurrence of the data object in O(1).
Counting sort can be extended to work for negative inputs also.
Counting sort is not a stable algorithm. But it can be made stable with some code changes.

*/

void countSort(vector<int> &arr){
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;
 
    vector<int> count(range), output(arr.size());
    
    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - min]++;
 
    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];
 
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
 
    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
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
        vector<int> array = {10, -3, 21, -9, 12, 31} ;
        countSort(array);
        for(int x : array){
            cout<<x<<" ";
        }
    }

}
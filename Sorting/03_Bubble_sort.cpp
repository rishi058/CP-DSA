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

Picture : Large Bubble(in water) goes to water-surface At first, then next smaller Bubble goes & so on...
          Similarly largest element goes to end of arr, then 2nd largest & so on...

1.  Currently Arr is divided into 2 parts [left(n-1 elements), right(1 elements)].
    { arr[0], arr[1], ..., arr[n-2] |  arr[n-1] }
    sorting is visible from right to left


*/

void print(vector<int> &v){
    for(int x : v){cout<<x<<", ";}
    cout<<"\n";
}

void bubbleSort(vi &arr){
    int n = arr.size();

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }

        print(arr);
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
        vi array = {4, 6, 5, 1, 3 ,2};
        bubbleSort(array);
        for (int x : array)
        {
            cout << x << " ";
        }
    }
}
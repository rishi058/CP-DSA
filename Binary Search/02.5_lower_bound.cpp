#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------
//  lower bound --> if a element is present return that element(or its leftmost (i.e first) index)
//                  if its not present return the element(or its idx) just greater than it.
//  NOTE -> if we search for a element greater than max_element its return -1;

// Use to find the location of left_most element in case of repetition (given that the element is already there)


int lowerBound(vector<int> &v, int target){
    int low = 0, high = v.size()-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(v[mid]<target){
            low = mid+1;
        }
        else if(v[mid]>=target){
            high = mid-1;
        }
    }
    return low==v.size()?-1:low;
}


int32_t main()
{
    vi arr = {2};
    // int n = arr.size()-1;
    int target = 3;
    int ind = lowerBound(arr,target);
    cout<<"Index : "<<ind;
}

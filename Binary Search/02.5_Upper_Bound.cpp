#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------
//  upper bound --> if a element is present(or not) return the element(or its index) which is just greater than it
//                  if its next greater element is not present(i.e element itself is the max_element) return -1.

// Use to find the location of right_most element in case of repetition (given that the element is already there)


int upperBound(vector<int> &v, int target){
    int low = 0, high = v.size()-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(v[mid]<=target){
            low = mid+1;
        }
        else if(v[mid]>target){
            high = mid-1;
        }
    }
    return low==v.size()?-1:low;
}


int32_t main()
{
    vi arr = {1,2,5,9,100,120,900,10002};
    int n = arr.size()-1;
    int target = 9;
    int ind = upperBound(arr,target);
    cout<<"Index : "<<ind;
}

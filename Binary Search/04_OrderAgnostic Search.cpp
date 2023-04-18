#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------
//  BINARY SEARCH in an array which is either ascending or descending sorted.. 


int BS(vi &v, int k, int low, int high, bool sorted){

    while(low<=high){

        int mid = low + (high-low)/2 ;

        if(v[mid]==k){return mid;}
        if(sorted){
            if(v[mid]<k){low = mid+1;}     
            if(v[mid]>k){high = mid-1;}
        }
        else{
            if(v[mid]>k){low = mid+1;}     // change the comparison sign
            if(v[mid]<k){high = mid-1;}
        }
    }

    return -1;

}

int32_t main()
{
    vi arr = {311,214,202,191,155,121,99,83,80,40,21,11}; // rev sorted array..
    int n = arr.size()-1;
    int k = 191;
    bool f = is_sorted(all(arr));
    int ind = BS(arr,k,0,n,f);
    cout<<"Index : "<<ind;
}
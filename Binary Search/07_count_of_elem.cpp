#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------
/*
if in a sorted or rev_sorted array, a element is repeated more 
than once then we have to find its first or last occurrence..
*/

int BS_1st_nd_last(vi &v, int k, int low, int high, bool first){

    int res = -1;

    while(low<=high){

        int mid = low + (high-low)/2 ;

        if(v[mid]==k){
            res = mid; 
            if(first){high = mid - 1;}
            else{low = mid+1;}
        }
        if(v[mid]<k){low = mid+1;}
        if(v[mid]>k){high = mid-1;}

    }

    return res;

}

int32_t main()
{
    vi arr = {1,1,2,4,4,4,6,6,6,7,8,9,11} ;
    int n = arr.size() - 1;
    int k = 4;
    int ind1 = BS_1st_nd_last(arr,k,0,n,true);
    int ind2 = BS_1st_nd_last(arr,k,0,n,false);
    cout<<"Count : "<<ind2-ind1+1;
}
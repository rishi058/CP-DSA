#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------
//  NORMAL BINARY SEARCH 


int BS(vi &v, int k, int low, int high){
    int mid;
    while(low<=high){

        mid = low + (high-low)/2 ;

        if(v[mid]==k){return mid;}
        if(v[mid]<k){low = mid+1;}
        if(v[mid]>k){high = mid-1;}

    }
    return mid; 
}

int32_t main()
{
    vi arr = {11,14,32,34,55,61,69,83,88,92,97,101};
    int n = arr.size()-1;
    int target = 900;
    int ind = BS(arr,target,0,n);
    cout<<"Index : "<<ind;
}
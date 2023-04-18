#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
// https://leetcode.com/problems/search-in-rotated-sorted-array/

// rotation == remove 1st element from the array and push_back it to the array.
// x times rotated array is given, we have to find x.
// x = n - ind(smallest). 


int B_search(vi &v, int low, int high,int k,bool search){  
    int n = high;
    if(!search){
        if(is_sorted(v.begin(), v.end())){return 0;}
        if(is_sorted(v.rbegin(), v.rend())){return n;}
        if(v.size()==2){return 1;}  
    }

    while(low<=high){

        int mid = low + (high-low)/2 ;

        if(search){                             // condition for normal BS
            if(v[mid]==k){return mid;}
            if(v[mid]<k){low = mid+1;}
            if(v[mid]>k){high = mid-1;}
        }
        else{                                  // consition for find smallest element in rotated sorted array.
            if(mid==0){
                if(v[0]<v[1]){return 0;}
                else{return 1;}
            }
            if(mid==n && v[n]<v[n-1]){return n;}
            else if(v[mid]<v[mid-1] && v[mid]<v[mid+1]){return mid;}
            else if(v[0]<v[mid]){low = mid+1;}
            else{high = mid-1;} 
        }

    }

    return -1;

} // returns index...


int32_t main()
{   
    vi arr = {11,12,13,14,16,25,2,3,6,9,10};
    int n = arr.size()-1;
    int ind = B_search(arr,0,n,-1,false);       // returns index of smallest element. 

    int k = 12;
    int ind2 = B_search(arr,0,ind-1,k,true);
    int ind3 = B_search(arr,ind,n,k,true);

    cout<<"No. of Rotation : "<<n-ind+1;
    cout<<"\nSearched Element Index : "<<max(ind2,ind3);
    
}
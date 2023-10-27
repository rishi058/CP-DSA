#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(v) v.begin(), v.end()
#define F(a,b,i) for (int i = a; i < b; i++)
#define Rev(a,b,i) for (int i = a; i >= b; i--)
#define RISHI ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
template <typename dStruct>
void print(dStruct& vName){for(auto &it : vName){cout<<it<<" ";} cout<<"\n";}
template <typename dStruct>
void print2(dStruct& vName){for(auto &it : vName){cout<<"{"<<it.first<<", "<<it.second<<"} ";} cout<<"\n";}
 
const int mod = 1e9 + 7;
#define inf LONG_LONG_MAX
#define Min LONG_LONG_MIN
 
typedef long double ld;
typedef vector<int> vi;
 
/*---------------------------------------->   MAGIC STARTS   <--------------------------------------------*/

/*
Given an array of n integers, your task is to calculate the number of subarrays that have at
most k distinct values.
*/

int32_t main()
{
    RISHI
    int n, k;
    cin>>n>>k;
 
    vi v(n);
    F(0,n,i){cin>>v[i];}
 
    unordered_map<int,int> freq;
    int unique_ct = 0, ans = 0;
    int i = 0, j = 0;
 
    while(j<n){
        if(freq[v[j]]==0){
            unique_ct++;
        }
        freq[v[j]]++;
 
        while(unique_ct>k){
            freq[v[i]]--;
            if(freq[v[i]]==0){unique_ct--;}
            i++;
        }
 
        ans += (j-i+1);
        j++;
    }   
 
    cout<<ans;
 
}
 

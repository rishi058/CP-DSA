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
There are n sticks with some lengths. Your task is to modify the sticks so that each stick has
the same length.
You can either lengthen and shorten each stick. Both operations cost c where c is the
difference between the new and original length.
*/

int32_t main()
{
    RISHI
    
    int n; cin>>n;
    vi v(n);
    F(0,n,i){cin>>v[i];}
 
    sort(all(v));
 
    if(n%2){
        int mid = v[n/2];
        int cost = 0;
        F(0,n,i){
            cost += abs(v[i]-mid);
        }
        cout<<cost<<"\n";
    }
 
    else{
        int idx = (n-1)/2;
        int mid1 = v[idx];
        int mid2 = v[idx+1];
 
        int cost1=0, cost2=0;
        F(0,n,i){
            cost1 += abs(v[i]-mid1);
            cost2 += abs(v[i]-mid2);
        }
 
        cout<<min(cost1, cost2)<<"\n";
    }
 
}

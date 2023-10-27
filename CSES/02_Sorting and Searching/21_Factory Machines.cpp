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
A factory has n machines which can be used to make products. Your goal is to make a total
of t products.
For each machine, you know the number of seconds it needs to make a single product. The
machines can work simultaneously, and you can freely decide their schedule.
What is the shortest time needed to make t products?
*/

bool check(vi &v, int time, int tot){
    int n = v.size(), prod_ct = 0;
    F(0,n,i){
        int ct = time/v[i]; // count_of_product v[i] machine will make under time=t.
        prod_ct += ct;
    }
    if(prod_ct>=tot){return 1;}
    return 0;
}
 
int32_t main()
{
    RISHI
   
    int n, x;
    cin>>n>>x;
    vi v(n);
    F(0,n,i){cin>>v[i];}
    sort(all(v));
    // print(v);
    int low = 0, high = v[0]*x, time = 0, ans;
    while(low<=high){
        time = (low+high)/2;
        bool ok = check(v, time, x);
        if(ok){ans=time;high=time-1;}
        else{low=time+1;}
    }
    cout<<ans;
    
 
}
 

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
There are n concert tickets available, each with a certain price. Then, m customers arrive,
one after another.
Each customer announces the maximum price they are willing to pay for a ticket, and after
this, they will get a ticket with the nearest possible price such that it does not exceed the
maximum price.
*/

int32_t main()
{
    RISHI
    
    int n, m;
    cin>>n>>m;
 
    multiset<int> tick;
    F(0,n,i){
        int x; cin>>x;
        tick.insert(x);
    }
 
    while(m--){
        int cost; cin>>cost;
        auto it = tick.lower_bound(cost);
 
        if(tick.empty()){cout<<"-1\n";}
        else if(*it==cost){
            cout<<cost<<"\n";
            tick.erase(it);
        }
        else if(it!=tick.begin()){
            it--;
            cout<<*it<<"\n";
            tick.erase(it);
        }
        else{
            cout<<"-1\n";
        }
    }
 
}

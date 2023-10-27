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
There are n apples with known weights. Your task is to divide the apples into two groups
so that the difference between the weights of the groups is minimal.
*/

bool isNthBitSet(int& number, int& n){
   int mask = 1 << n;
   return (number & mask) != 0;
}
 
int32_t main()
{
    RISHI
    int n; cin>>n;
    vi v(n);
    int sum = 0;
    F(0,n,i){cin>>v[i]; sum+=v[i];}
 
    int ans = inf;
 
    F(0,(1<<n),i){
        int curr = 0;
        F(0,n,j){
            if(isNthBitSet(i,j)){
                curr += v[j];
            }
        }
        int left = sum - curr;
        ans = min(ans, abs(curr-left));
    }
 
    cout<<ans<<"\n";
}

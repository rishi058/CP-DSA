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
 
int32_t main()
{
    RISHI
    int n, target;
    cin>>n>>target;
 
    vector<pair<int,int>> vp;
    F(0,n,i){
        int x; cin>>x;
        vp.push_back({x,i+1});
    }
    sort(all(vp));
    // print2(vp);
    bool ok = 1;
 
    F(0,n-1,i){
        int new_target = target-vp[i].first;
        int ptr1 = i+1, ptr2 = (n-1);
        while(ptr1<ptr2){
            int sum = vp[ptr1].first+vp[ptr2].first;
            if(sum==new_target){
                cout<<vp[i].second<<" "<<vp[ptr1].second<<" "<<vp[ptr2].second<<"\n";
                ok = 0;
                break;
            }
            else if(sum<new_target){
                ptr1++;
            }
            else{ptr2--;}
        }
        if(!ok){break;}
    }
 
    if(ok){cout<<"IMPOSSIBLE\n";}
}

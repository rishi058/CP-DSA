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
In a movie festival n movies will be shown. You know the starting and ending time of each movie.
What is the maximum number of movies you can watch entirely?
*/

bool cmp(pair<int,int>&a, pair<int,int>&b){
    return a.second<b.second;
}
 
int32_t main()
{
    RISHI
    
    int n; cin>>n;
    vector<pair<int,int>> vp;
 
    F(0,n,i){
        int a,b;
        cin>>a>>b;
        vp.push_back({a,b});
    }
 
    sort(all(vp), cmp);
 
    int ans = 1;
    int curr = vp[0].second;
    F(1,n,i){
        if(vp[i].first>=curr){
            ans++;
            curr = vp[i].second;
        }
    }
 
    cout<<ans<<"\n";
}

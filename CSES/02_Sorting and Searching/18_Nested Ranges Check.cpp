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
Given n ranges, your task is to determine for each range if it contains some other range and
if some other range contains it.

Range [a, b] contains range [c,d] if a <= c and d <= b.
*/

struct range{
    int l,r,id;
    range(int a, int b, int c){
        l = a, r = b, id = c;
    }
};
 
bool cmp(range &a,range &b){
    if(a.l==b.l){return a.r>b.r;}
    else{return a.l<b.l;}
}
 
int32_t main()
{
    RISHI
    int n; cin>>n;
 
    vector<range> v;
 
    F(0,n,i){
        int l, r;
        cin>>l>>r;
        v.push_back(range(l,r,i));
    }
 
    sort(all(v), cmp);
 
    vector<int>contained(n); // kisi ke andr ye khud hai ya nhi
    vector<int>contains(n); // kisi ko andr rkha hai ya nhi
 
    int maxend = 0;
    for(int i = 0; i<n; i++){
        if(v[i].r <= maxend) {contained[v[i].id] = true;}
        maxend = max(maxend , v[i].r);
    }
 
 
    int minend = INT_MAX;
    for(int i = n - 1; i>= 0 ; i--){
        if(v[i].r >= minend) {contains[v[i].id] = true;}
        minend = min(minend , v[i].r);
    }
 
    print(contains);
    print(contained);
}



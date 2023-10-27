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
You are given an array of n positive integers. Your task is to find two integers such that their greatest
common divisor is as large as possible.
*/

const int MAX = 1e6+1;
int cnt[MAX];
 
int32_t main()
{
    RISHI
    int n; cin>>n;
    int mx = 0;
    F(0,n,i){int x; cin>>x; cnt[x]++; mx = max(mx, x);}
 
    for(int i=mx; i>0; i--){
        int ct=0;
        for(int j=i; j<=mx; j+=i){ct+=cnt[j];}
        if(ct>=2){
            cout<<i;
            break;
        }
    }
 
}

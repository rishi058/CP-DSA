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
There are n books, and Kotivalo and Justiina are going to read them all. For each book, you
know the time it takes to read it.
They both read each book from beginning to end, and they cannot read a book at the same
time. What is the minimum total time required?
*/

int32_t main()
{
    RISHI
    int n; cin>>n;
    int mx=0, sum=0;
    F(0,n,i){
        int x; cin>>x;
        sum += x;
        mx = max(mx, x);
    }
 
    cout<<max(mx*2, sum);
}

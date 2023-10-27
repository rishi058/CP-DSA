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
You have two coin piles containing a and b coins. On each move, you can either remove one coin from the
left pile and two coins from the right pile, or two coins from the left pile and one coin from the right pile.

Your task is to efficiently find out if you can empty both the piles.
*/

int32_t main()
{
    RISHI
    int T; cin>>T;
    while(T--)
    {
        int a, b;
        cin>>a>>b;
 
        int rem = (a+b)%3;
 
        if(rem!=0){cout<<"NO\n";}
        else{
            int q = (a+b)/3;
            int x = a - q;
            int y = b - q;
            if(x>=0 && y>=0){cout<<"YES\n";}
            else{cout<<"NO\n";}
        }
    }
 
}

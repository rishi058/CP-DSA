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
 
#define mod 1e9+7
#define inf LONG_LONG_MAX
#define Min LONG_LONG_MIN
 
typedef long double ld;
typedef vector<int> vi;
 
/*---------------------------------------->   MAGIC STARTS   <--------------------------------------------*/

/*
A number spiral is an infinite grid whose upper-left square has number 1. Here are the first five layers of the spiral:
Your task is to find out the number in row y and column x.

Constraints
• 1 < t < 10^5
• 1 <= x,y <= 10^9
*/

int32_t main()
{
    RISHI
    int T; cin>>T;
    while(T--)
    {
        int x, y;
        cin>>x>>y;
 
        int ax, ay;
 
        if(x%2){ax = (x-1)*(x-1) + 1;}
        else{ax = x*x;}
 
        if(y%2){ay = y*y;}
        else{ay = (y-1)*(y-1) + 1;}
 
        if(x>=y){
            if(x%2){ax+=(y-1);}
            else{ax-=(y-1);}
            cout<<ax<<"\n";
        }
        else{
            if(y%2){ay-=(x-1);}
            else{ay+=(x-1);}
            cout<<ay<<"\n";
        }
    }
 
}

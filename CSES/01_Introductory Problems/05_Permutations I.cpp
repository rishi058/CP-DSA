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
A permutation of integers 1, 2, ... , n is called beautiful if there are no adjacent elements
whose difference is 1.
Given n, construct a beautiful permutation if such a permutation exists.
*/

int32_t main()
{
    RISHI
    int n; cin>>n;
    
    if(n==1){cout<<"1\n";}
    else if(n<4){cout<<"NO SOLUTION\n";}
    else if(n==4){cout<<"3 1 4 2\n";}
    else{
        F(1,n+1,i){
            cout<<i<<" ";
            i++;
        }
        F(2,n+1,i){
            cout<<i<<" ";
            i++;
        }
        cout<<"\n";
    }
}

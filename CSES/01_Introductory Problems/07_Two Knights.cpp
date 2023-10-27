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
Your task is to count for k = 1, 2, ... ,n the number of ways two knights can be placed on a
k x k chessboard so that they do not attack each other.
*/

int32_t main()
{
    RISHI
    int n; cin>>n;
    F(1,n+1,i){
        if(i==1){cout<<"0\n";}
        else if(i==2){cout<<"6\n";}
        else{
            int tot = ((i*i)*(i*i - 1))/2;
            int attack = 4*(i-1)*(i-2);
            cout<<tot-attack<<"\n";
        }
    }
}

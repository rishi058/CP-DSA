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
 
vector<pair<char, char>> vp;
 
void TOH(int n, char from_rod, char to_rod, char aux_rod){
    if(n == 0){return;}
    TOH(n - 1, from_rod, aux_rod, to_rod);
    // cout << "Move disk " << n << " from rod " << from_rod <<  " to rod " << to_rod << endl;
    vp.push_back({from_rod, to_rod});
    TOH(n - 1, aux_rod, to_rod, from_rod);
}
 
 
int32_t main()
{
    RISHI
    int n; cin>>n;   // no. of disks
 
    TOH(n, '1', '3', '2');
 
    cout<<vp.size()<<"\n";
    for(auto it : vp){
        cout<<it.first<<" "<<it.second<<"\n";
    }
 
}
 

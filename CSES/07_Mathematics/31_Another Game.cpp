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
There are n heaps of coins and two players who move alternately. On each move, a player
selects some of the nonempty heaps and removes one coin from each heap. The player who
removes the last coin wins the game.
Your task is to find out who wins if both players play optimally.
*/

int32_t main()
{
    RISHI
    int T = 1;
    cin>>T;
    while(T--)
    {
        int n; cin>>n;
        int odd_ct = 0;
        F(0,n,i){int x; cin>>x; if(x%2){odd_ct++;}}
 
        if(odd_ct==0){cout<<"second\n";}
        else{cout<<"first\n";}
 
    }
 
}
 

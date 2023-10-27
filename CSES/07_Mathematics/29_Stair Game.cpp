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
There is a staircase consisting of n stairs, numbered 1, 2, . .. , n. Initially, each stair has some
number of balls.
There are two players who move alternately. On each move, a player chooses a stair k
where k 1 and it has at least one ball. Then, the player moves any number of balls from
stair k to stair k — 1. The player who moves last wins the game.
Your task is to find out who wins the game when both players play optimally.
Note that if there are no possible moves at all, the second player wins.
*/

int32_t main()
{
    RISHI
    int T = 1;
    cin>>T;
    while(T--)
    {
        int n; cin>>n;
        vi v(n);
        F(0,n,i){cin>>v[i];}
 
        int xxor = 0;
        F(0,n,i){
            if(i%2==0){continue;}
            xxor ^= v[i];
        }
 
        if(xxor==0){cout<<"second\n";}
        else{cout<<"first\n";}
    }
 
}
 

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
Consider a game where two players remove sticks from a heap. The players move
alternately, and the player who removes the last stick wins the game.

A set P = {P1,P2, ... ,Pk} determines the allowed moves. For example, if P = {1, 3, 4}, a
player may remove 1, 3 or 4 sticks.

Your task is find out for each number of sticks 1, 2, ...,n if the first player has a winning or
losing position.
*/

int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        int n, k;
        cin>>n>>k;
 
        vector<bool> dp(n+1, 0);
 
        vi v(k);
        F(0,k,i){cin>>v[i]; dp[v[i]]=1;}
        sort(all(v));
 
        for(int i=1; i<=n; i++){
            for(int j=0; j<k; j++){
                if(i-v[j]<0){break;}
                if(dp[i-v[j]]==0){dp[i]=1;}
            }
        }
 
        string ans;
        for(int i=1; i<=n; i++){
            if(dp[i]){ans.push_back('W');}
            else{ans.push_back('L');}
        }
        cout<<ans;
    }
 
}

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
here are n people who want to get to the top of a building which has only one elevator. You
now the weight of each person and the maximum allowed weight in the elevator. What is
he minimum number of elevator rides?
*/

bool isNthBitSet(int& number, int& n){
   int mask = 1 << n;
   return (number & mask) != 0;
}
 
void flipNthBit(int& number, int n){
   int mask = 1 << n;
   number = number ^ mask;
}
 
int32_t main()
{
    RISHI
    int n, wt_limit;
    cin>>n>>wt_limit;
 
    vi wt(n);
    F(0,n,i){cin>>wt[i];}
 
    pair<int,int> dp[1<<n];
 
    /*
 
    dp[i] = {first,sec} : 
    first = min no. of rides needed to cover "i"-subset people.
    sec = the minimum weight of people who ride in the last group.
    
	Loop through all bitmasks.
	The bitmasks represent whether each person has used the elevator or not.
	If the ith bit is set, this means the ith person has used the elevator.
 
	*/
 
    dp[0] = {1,0};
 
    for(int s=1; s<(1<<n); s++){  // s = subset
        dp[s] = {n+1,0};
 
        for(int p=0; p<n; p++){
            // The ith person has used the elevator.
            if(isNthBitSet(s,p)){
                int x = s; flipNthBit(x, p);
 
                int prev_rides =  dp[x].first;
                int prev_wt    =  dp[x].second;
 
                // We need to use a new ride.
                if(prev_wt + wt[p] <= wt_limit){
                    prev_wt += wt[p];
                }
                else{
                    // Add the weight of the ith person to the current ride.
                    prev_rides++;
                    prev_wt = wt[p];
                }
 
                // Update if it is better than the original.
                dp[s] = min(dp[s], {prev_rides, prev_wt});
            }
        }
 
    }
 
    // Result when all people have used the elevator.
    cout<<dp[(1<<n)-1].first;
 
}
 

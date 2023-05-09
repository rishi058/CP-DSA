#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*
In Knapsack When W(limit) value is very high(i.e >1e5) we can't make a 2D array of this size..
So we have to think of difrrent Method......

APPROACH -->
We will consider dp[arr_size][value(V)]  --> Where value = THis value(V) Obtained using minimum weight..

Intuition Breakdown -->

dp[i][j] = Min_wt_possible if we use items only from 0 to "i" and the profit we want to make is exactly "j".

for all dp[i][j] = wt_max  [ intilally no_ans exists for any i,j. And also We use min function for calculations, therfore intializing everything @ mx]

for all i, dp[i][0] = 0    [ if req_profit i.e "j" = 0, then no matter how many elements we have, ANS is always possible
                            and Weight will be 0(bcz we are selceting 0 items every time)]

if(val[i]<=j){                             // check if the price of i'th element <= req_profit we want to make [for checking if it is possible to include i'th element or not]
    int ans1 = wt[i] + dp[i-1][j-val[i]] ; // [selecting i'th item] including the wt[i] + min_wt possible if we have elements from 0 to i-1 and req_exact_profit is "j-price[i]" ;
    int ans2 = dp[i-1][j] ;                // [not selecting i'th item] min_wt possible if we want to have req_exact_profit = "j" and selecting elements only from 0 to i-1 ;
    dp[i][j] = min(ans1, ans2);            // selecting min of both case.
}
else{
    dp[i][j] = min(dp[i-1][j], wt_max);
}

*/

#define wt_max  1000000007   // wt_max = 1e9+7 or wt_limit+1 ;
 
int knapsack2(vector<int>& wt, vector<int>& val, int n, int wt_limit){
    int val_max = accumulate(all(val), 0);

    int dp[n+1][val_max+1];

    // initialize
    for (int i=0; i<=n; i++){
        for (int j=0; j<=val_max; j++){
            dp[i][j] = wt_max;
        }
    }
        
    // Base case initialization
    for (int i=0; i<=n; i++){
        dp[i][0] = 0;
    }
 
    // iterate over subproblems ans get
    // the current value from previous computation
    for (int i=1; i<=n; i++){
        for (int j=1; j<=val_max; j++){
            if(val[i]<=j){
                dp[i][j] = min(dp[i-1][j], wt[i] + dp[i-1][j-val[i]]);
            }
            else{
                dp[i][j] = min(dp[i-1][j], wt_max);
            }
        }
    }

    // Finding maximum value
    for (int i=val_max; i>=0; i--){
        if (dp[n][i] <= wt_limit){
            return i;
        }
    }
 
    return 0;
}
 
int32_t main(){

    vector<int> wt = { 10, 20, 30 };
    vector<int> val = { 60, 100, 120 };
    int n = (int)wt.size();
    int wt_limit = 50;

    val.insert(val.begin(), 0);
    wt.insert(wt.begin(), 0);
 
    cout << knapsack2(wt, val, n, wt_limit);
}

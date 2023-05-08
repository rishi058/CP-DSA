#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*
given an arr nd a sum print YES if there is a subet of arr whose sum is equal to given sum...else NO..
*/

/*
Intuition BreakDown -->

dp[i][j] = represents ans(TRUE/FALSE) if we use elements of arr ranging from 0 to "i" and the req_sum is "j".

NOTE :- 0th index means currently no element.

if(j==0){               // req_sum is Zero(0) i.e ans = select no elements.
    dp[i][j] = TRUE;
}
else if(j>0 && i==0){   // req_sum(j) is greater than Zero(0) but we have no elements to select(i.e i==0) Therefore ans is not_possible. 
    dp[i][j] = FALSE;
}
else{
    if(v[i]<=j){        // if curr_element is less than equal to required_sum..
        int ans1 = dp[i-1][j-v[i]] ;   // use ith element..
        int ans2 = dp[i-1][j] ;        // don't use ith element..
        dp[i][j] = ans1 || ans2;  

        NOTE :- dp[i-1][j-v[i]] = if it is possible to achieve req_sum = (j-v[i]) using elements from 0 to i-1. [1 row up and little back]
    }
    else{
        dp[i][j] = dp[i-1][j];  
        NOTE :- dp[i-1][j] represents if it is possible to achieve req_sum = "j" using upto i-1 elements. [ just up (1 row up only) ]
    }  
}
*/

int32_t main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vi v(n+1);

        F(0,n,i){
            cin>>v[i+1];    // 1 indexed
        }                               
        

        int required_sum; cin>>required_sum;

        bool dp[n+1][required_sum+1];

        F(0,n+1,i){
            F(0,required_sum+1, j){
                if(j>0 && i==0 ){dp[i][j]=false;}
                else if(j==0){dp[i][j]=true;}
                
                else{
                    if(v[i]<=j){
                        dp[i][j] = dp[i-1][j-v[i]] || dp[i-1][j] ;
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
                
            }
        }

        if(dp[n][required_sum]){cout<<"YES\n";}
        else{cout<<"NO\n";}
        
        F(0,n+1,i){
            F(0,required_sum+1, j){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
    
    }

}
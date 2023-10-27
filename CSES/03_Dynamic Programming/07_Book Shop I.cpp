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
You are in a book shop which sells n different books. You know the price and number of
pages of each book.
You have decided that the total price of your purchases will be at most c. What is the
maximum number of pages you can buy? You can buy each book at most once.
*/

int32_t main()
{
    RISHI
    int n, wt_limit;
    cin>>n>>wt_limit;
    
    vi wt(n+1), val(n+1);
    F(0,n,i){
        cin>>wt[i+1];
    }                               // 1 indexed
    F(0,n,i){
        cin>>val[i+1];
    }
 
    int dp[2][wt_limit+1];
 
    F(0,n+1,i){
        F(0,wt_limit+1, j){
            if(i==0||j==0){
                dp[i%2][j]=0;
            }
            else{
                if(wt[i]<=j){ 
                    dp[i%2][j]=max(val[i]+dp[(i-1)%2][j-wt[i]], dp[(i-1)%2][j]);
                }
                else{
                    dp[i%2][j] = dp[(i-1)%2][j];
                }
            }
        }
    }
    cout<<dp[n%2][wt_limit]<<"\n";
 
}

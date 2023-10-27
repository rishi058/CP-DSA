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
The edit distance between two strings is the minimum number of operations required to
transform one string into the other.
The allowed operations are:
• Add one character to the string.
• Remove one character from the string.
• Replace one character in the string.
*/

string s1, s2;
vector<vector<int>> dp;
 
int solve(int idx1, int idx2){
    if(idx1<0){return idx2+1;}
    if(idx2<0){return idx1+1;}
 
    if(dp[idx1][idx2]!=-1){return dp[idx1][idx2];}
 
    if(s1[idx1]==s2[idx2]){
        dp[idx1][idx2] = solve(idx1-1, idx2-1);
    }
    else{
        int a = solve(idx1-1, idx2);
        int b = solve(idx1, idx2-1);
        int c = solve(idx1-1, idx2-1);
        dp[idx1][idx2] = min({a,b,c}) + 1;
    }
    
    return dp[idx1][idx2];
}
 
int32_t main()
{
    RISHI
    cin>>s1>>s2;  // change s1 to s2 or s2 to s1
 
    int n = s1.size(), m = s2.size();
    dp.resize(n, vector<int>(m, -1));
 
    cout<<solve(n-1,m-1);
}

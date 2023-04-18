#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*

Given a String, you have to divide/partition it in such a way that it partioned string is a palindrome itself...
Output the no. of Partioned required...

*/

int dp[10001][10001];

bool isPal(string &s, int i, int j){
    bool ans = true;
    while(i<j){
        if(s[i]!=s[j]){ans=false; break;}
        i++; j--;
    }
    return ans;
}

int solve(string &s, int i, int j){
    if(i>=j){ return 0;}

    if(isPal(s,i,j)==true){return 0;}

    if(dp[i][j]!=-1){return dp[i][j];}

    int mn = INT_MAX;

    F(i,j,k){
        int left, right;

        if(dp[i][k]!=-1){
            left = dp[i][k] ;
        }
        else{
            left = solve(s,i,k);
            dp[i][k] = left;
        }

        if(dp[k+1][j]!=-1){
            right = dp[k+1][j] ;
        }
        else{
            right = solve(s,k+1,j);
            dp[k+1][j] = right;
        }


        int temp = 1 + left + right ;
        mn = min(mn, temp);
    }

    return dp[i][j] = mn ;
}

int32_t main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;
    while(t--)
    {

        string s; cin>>s;
        int n = s.size();

        memset(dp, -1, sizeof(dp));
        cout<<solve(s,0,n-1) ;
    }

}
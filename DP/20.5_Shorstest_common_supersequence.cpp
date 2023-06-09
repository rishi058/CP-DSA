#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------
// https://leetcode.com/problems/shortest-common-supersequence/submissions/936187810/

// 1
// AGGTAB
// GXTXAYB

string solve(string s1, string s2){
    s1 = '0' + s1;
    s2 = '0' + s2;

    int n = s1.size(), m = s2.size();
    int dp[n][m];

    F(0,n,i){
        F(0,m,j){
            if(i==0){
                dp[i][j] = j;
            } 
            else if(j==0){
                dp[i][j] = i;
            }
            else if (s1[i] == s2[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }

            else{
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
    }

    int i=n, j=m;
    string ans;

    while(i>0 && j>0){
        if(s1[i]==s2[j]){
            ans.push_back(s1[i]);
            i--;
            j--;
        }
        else if(dp[i][j-1] < dp[i-1][j]){
            ans.push_back(s2[j]);
            j--;
        }
        else
        {
            ans.push_back(s1[i]);
            i--;
        }
    }

    while(i>0){
        ans.push_back(s1[i]);
        i--;
    }
    while(j>0){
        ans.push_back(s2[j]);
        j--;
    }

    reverse(ans.begin(), ans.end());
    ans.pop_back();
    return ans;
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
        string s1, s2;
        cin>>s1>>s2;

        cout<<solve(s1,s2);

    }

}

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*

Derivatives of LCS -->
1. Longest common Subsequence.
2. Print LCS.
3. Shortest common Supersequence.
4. Print SCS.
5. Min no. of Insertion and Deletion to transform a to b.
6. Largest Reapeating Subsequence.
7. Length Of Largest Subsequnce of A which is Substring of B.
8. Subsequence Pattern Matching.
9. Ct. of appearances Of subsequence A in B.
10. Largest palindromic Subsequence.
11. Largest Palindromic Substring.
12. ct of Palindromic Substring.
13. Min no. of Deletion in a string to make it a Palindrome.  
14. Min no. of Insertion in a string to make it a Palindrome. 

1
abacc
aabbc

*/

/*

Intuiton Breakdown --> 

if(i==0 || j==0){ dp[i][j] = 0;}  // i.e if any 1 of the string is empty LCS will obviously 0.

 
else if(s1[i]==s2[j]){              // IMP -> if s1[i]==s2[j] then we will include this in our LCS , and we will need to add it in LCS
    dp[i][j] = 1 + dp[i-1][j-1];    // when s1[i] & s2[j] is not the part, therfore + dp[i-1][j-1];
}

else{
    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);  // since s1[i]!=s2[j], we can't include it, but we need to fill dp[i][j] with curr_optimal LCS, 
}                                          // therefore we take max_LCS of 2 cases -> (include s1[i] & not s2[j]), vice-versa. 

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
        string s1, s2;
        cin>>s1>>s2;

        s1 = '0'+s1;
        s2 = '0'+s2;

        int n = s1.size(), m = s2.size();

        int dp[n][m];

        F(0,n,i){
            F(0,m,j){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                }
                else if(s1[i]==s2[j]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        cout<<dp[n-1][m-1]<<"\n";
        F(0,n,i){
            F(0,m,j){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }


    }

}
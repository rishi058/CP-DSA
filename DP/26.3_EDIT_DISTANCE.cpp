#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
#define F(a,b,i) for (int i = a; i < b; i++)
#define RISHI ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------
//https://leetcode.com/problems/edit-distance/

/*

QUESTION -->

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:
Insert a character
Delete a character
Replace a character

NOTE :- converting s1 to s2 or s2 to s1 require same no. of steps. [Delete opr is rev of Insert opr]

if(s1[i]!=s2[j]){
    int a = dp[i][j-1] ;           // insert a character at the end of s1
    int b = dp[i-1][j] ;           // remove the last character from of s1
    int c = dp[i-1][j-1] ;         // modify the last character of s1
    dp[i][j] = min(a,b,c) + 1 ;
}

*/

int minDistance(string s1, string s2) {
    
    s1 = '0'+s1;
    s2 = '0'+s2;

    int n = s1.size(), m = s2.size();

    int dp[n][m];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i+j==0){dp[i][j]=0;}
            else if(i==0){dp[i][j] = dp[i][j-1]+1;}
            else if(j==0){dp[i][j] = dp[i-1][j]+1;}
            else if(s1[i]==s2[j]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
            }
        }
    }

    return dp[n-1][m-1]; 
}

int32_t main()
{
    RISHI
    string s1 = "LOVE", s2 = "MOVIE";
    // ans = 2 [ c++ cheat sheet pdf page-84 ]

}



// ███████╗██╗███╗   ██╗██╗███████╗██╗  ██╗    ██╗    ██╗██╗  ██╗ █████╗ ████████╗    ██╗   ██╗ ██████╗ ██╗   ██╗    ███████╗████████╗ █████╗ ██████╗ ████████╗    ██╗
// ██╔════╝██║████╗  ██║██║██╔════╝██║  ██║    ██║    ██║██║  ██║██╔══██╗╚══██╔══╝    ╚██╗ ██╔╝██╔═══██╗██║   ██║    ██╔════╝╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝    ██║
// █████╗  ██║██╔██╗ ██║██║███████╗███████║    ██║ █╗ ██║███████║███████║   ██║        ╚████╔╝ ██║   ██║██║   ██║    ███████╗   ██║   ███████║██████╔╝   ██║       ██║
// ██╔══╝  ██║██║╚██╗██║██║╚════██║██╔══██║    ██║███╗██║██╔══██║██╔══██║   ██║         ╚██╔╝  ██║   ██║██║   ██║    ╚════██║   ██║   ██╔══██║██╔══██╗   ██║       ╚═╝
// ██║     ██║██║ ╚████║██║███████║██║  ██║    ╚███╔███╔╝██║  ██║██║  ██║   ██║          ██║   ╚██████╔╝╚██████╔╝    ███████║   ██║   ██║  ██║██║  ██║   ██║       ██╗
// ╚═╝     ╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝     ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝          ╚═╝    ╚═════╝  ╚═════╝     ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝       ╚═╝
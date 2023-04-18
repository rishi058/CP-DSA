#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*

Given an array -> { 40, 20, 30, 10, 30 } where n = 5;
representing the dimesion for (n-1) Matrices whose  dimensions are arr[0]*arr[1], arr[1]*arr[2], arr[2]*arr[3] ...;
Cost of Multiplication(COM) of two Marices A(a*b), B(b*c) is = (a*b*c) ;

You have two multiply (n-1) arr in such a way/Order that the COM is Min..;
Output the Min COM;


T.C = O(2^N) -> approx exponential {brute force recursion}
S.C -> O(1) -> {brute force recursion}

T.C = O(N^3) -> {while memoization or tabulation}
S.C -> O(N^2) -> {while memoization or tabulation}

*/

int dp[1000][1000] ;   // [arr.size()][arr.size()] --> [i][j] represents answer of arr range ( i to j ) .

int MCM(int arr[], int i, int j){
    if(i>=j){return 0;}
    if(dp[i][j]!=-1){return dp[i][j];}

    int ans = INT_MAX ;

    F(i,j,k){

        int temp_ans = MCM(arr, i , k) + MCM(arr, k+1, j) + arr[i-1]*arr[k]*arr[j] ;

        ans = min(temp_ans, ans);

        dp[i][j] = ans;
    }

    return dp[i][j] = ans;

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
        memset(dp, -1, sizeof(dp));
        int arr[5] = {  10, 40, 30, 25, 9 } ;
        cout<<MCM(arr, 1 , 4) ;
    }

}
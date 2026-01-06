#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int N, vector<int> A, vector<int> Z) {
    long long MOD = 1e9 + 7;
    vector<long long> dp(N, 0);
    long long total_count = 0;

    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        int limit = i - Z[i] + 1;
        for (int j = i - 1; j >= max(0, limit); j--) {
            if (A[i] > A[j]) {
                if (A[i] % A[j] != 0 && A[j] % A[i] != 0) {
                    dp[i] = (dp[i] + dp[j]) % MOD;
                }
            }
        }
        total_count = (total_count + dp[i]) % MOD;
    }
    return (int)total_count;
}

int main() {
    // Case 1: N=2, A=[2,3], Z=[1,1] -> Exp: 2
    cout << "Case 1: " << solve(2, {2, 3}, {1, 1}) << " (Exp: 2)" << endl;
    
    // Case 2: N=2, A=[2,3], Z=[1,2] -> Exp: 3
    cout << "Case 2: " << solve(2, {2, 3}, {1, 2}) << " (Exp: 3)" << endl;

    // Case 3: N=3, A=[1,2,3], Z=[1,2,3] -> Exp: 4
    cout << "Case 3: " << solve(3, {1, 2, 3}, {1, 2, 3}) << " (Exp: 4)" << endl;

    // Hard Case: N=5, A=[2,4,3,7,5], Z=[1,2,3,4,5]
    // 1-len: {2}, {4}, {3}, {7}, {5} (5)
    // 2-len: {2,3}, {2,7}, {2,5}, {4,3}, {4,7}, {4,5}, {3,7}, {3,5}, {7,5} (Invalid)
    // Applying divisibility: 4%2==0 (No), 7%3!=0, 5%7!=0 etc.
    cout << "Hard Case: " << solve(5, {2, 4, 3, 7, 5}, {1, 2, 3, 4, 5}) << endl;

    return 0;
}
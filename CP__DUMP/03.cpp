#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// const int INF = 1e9;

// struct SegTree {
//     int n;
//     vector<int> tree;
//     SegTree(int _n, const vector<int>& b) : n(_n) {
//         tree.resize(4 * n);
//         build(b, 1, 0, n - 1);
//     }
//     void build(const vector<int>& b, int v, int tl, int tr) {
//         if (tl == tr) tree[v] = b[tl];
//         else {
//             int tm = (tl + tr) / 2;
//             build(b, 2 * v, tl, tm);
//             build(b, 2 * v + 1, tm + 1, tr);
//             tree[v] = max(tree[2 * v], tree[2 * v + 1]);
//         }
//     }
//     int query(int v, int tl, int tr, int l, int r) {
//         if (l > r) return 0;
//         if (l == tl && r == tr) return tree[v];
//         int tm = (tl + tr) / 2;
//         return max(query(2 * v, tl, tm, l, min(r, tm)),
//                    query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
//     }
// };

// long long solve(int n, vector<int> a, vector<int> b) {
//     vector<vector<int>> pos(n + 1);
//     for (int i = 0; i < n; i++) pos[a[i]].push_back(i);

//     SegTree st(n, b);
//     long long txp = 0;

//     for (int i = 0; i < n; i++) {
//         int p = a[i], r = INF;
//         for (int m = p; m <= n; m += p) {
//             auto it = upper_bound(pos[m].begin(), pos[m].end(), i);
//             if (it != pos[m].end()) r = min(r, *it);
//         }

//         if (r != INF) txp += st.query(1, 0, n - 1, i, r);
//     }
//     return txp;
// }

long long solve(int N, vector<int> A, vector<int> Bonus) {
    int maxA = N / 2;
    const int INF = 1e9;

    int LOG = 0;
    while ((1 << LOG) <= N) LOG++;
    vector<vector<int>> st(LOG, vector<int>(N));

    for (int i = 0; i < N; i++) st[0][i] = Bonus[i];
    for (int k = 1; k < LOG; k++) {
        for (int i = 0; i + (1 << k) <= N; i++) {
            st[k][i] = max(st[k - 1][i],
                           st[k - 1][i + (1 << (k - 1))]);
        }
    }

    auto rangeMax = [&](int l, int r) {
        int len = r - l + 1;
        int k = 31 - __builtin_clz(len);
        return max(st[k][l], st[k][r - (1 << k) + 1]);
    };
    
    vector<int> nearest(maxA + 1, INF);
    long long ans = 0;

    for (int i = N - 1; i >= 0; i--) {
        int v = A[i];
        int R = INF;

        for (int m = v; m <= maxA; m += v) {
            R = min(R, nearest[m]);
        }

        if (R != INF) {
            ans += rangeMax(i, R);
        }

        nearest[v] = i;
    }
    return ans;
}

int main() {
    // Case 1
    cout << "Case 1: " << solve(4, {1, 1, 2, 2}, {4, 2, 8, 1}) << " (Exp: 18)" << endl;

    // Case 2
    cout << "Case 2: " << solve(6, {1, 2, 3, 1, 2, 3}, {4, 2, 1, 4, 5, 9}) << " (Exp: 23)" << endl;

    // Case 3
    // Manually calculated based on rules: N=3, A=[1, 2, 1], Bonus=[3, 5, 4]
    // i=0 (A[0]=1): Right multiples (2 or 1) are at index 1 and 2. R=1. Max Bonus[0,1]=5.
    // i=1 (A[1]=2): No multiples of 2 to the right.
    // i=2 (A[2]=1): No soldiers to the right.
    // Total = 5.
    cout << "Case 3: " << solve(3, {1, 2, 1}, {3, 5, 4}) << " (Exp: 5)" << endl;

    return 0;
}
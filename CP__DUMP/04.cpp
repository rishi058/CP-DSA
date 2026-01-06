#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

struct Node {
    int sz;
    vector<ll> t;
    Node(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        t.assign(2 * sz, -2e18);
    }
    void upd(int i, ll v) {
        for (i += sz, t[i] = v, i /= 2; i > 0; i /= 2)
            t[i] = max(t[2 * i], t[2 * i + 1]);
    }
    ll query(int l, int r) {
        ll res = -2e18;
        for (l += sz, r += sz; l <= r; l /= 2, r /= 2) {
            if (l % 2 == 1) res = max(res, t[l++]);
            if (r % 2 == 0) res = max(res, t[r--]);
        }
        return res;
    }
};

int get_ans(int n, vector<int> a, vector<int> len) {
    vector<ll> px(n + 1, 0), ps(n + 1, 0);
    unordered_map<int, vector<int>> pos;
    pos[0].push_back(0);
    for (int i = 0; i < n; i++) {
        px[i + 1] = px[i] ^ a[i];
        ps[i + 1] = ps[i] + a[i];
        pos[px[i + 1]].push_back(i + 1);
    }

    unordered_map<int, Node*> trees;
    unordered_map<int, int> cur;
    for (auto& p : pos) {
        trees[p.first] = new Node(p.second.size());
        cur[p.first] = 0;
    }

    vector<ll> dp(n + 1, 0);
    trees[0]->upd(0, 0);
    cur[0] = 1;

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        int x = px[i], lim = i - len[i - 1];
        auto& idxs = pos[x];
        int start = lower_bound(idxs.begin(), idxs.end(), lim) - idxs.begin();
        int end = cur[x] - 1;

        if (start <= end) {
            ll best = trees[x]->query(start, end);
            if (best > -1e17) dp[i] = max(dp[i], ps[i] + best);
        }
        trees[x]->upd(cur[x]++, dp[i] - ps[i]);
    }

    ll res = (ps[n] - dp[n]) % MOD;
    for (auto& p : trees) delete p.second;
    return (int)((res + MOD) % MOD);
}

int main() {
    // Case 1: N=2, A=[1, 1], Len=[1, 2] -> Exp: 0
    cout << "Case 1: " << get_ans(2, {1, 1}, {1, 2}) << " (Expected: 0)" << endl;

    // Case 2: N=2, A=[1, 1], Len=[1, 1] -> Exp: 2
    cout << "Case 2: " << get_ans(2, {1, 1}, {1, 1}) << " (Expected: 2)" << endl;

    // Case 3: N=4, A=[1, 2, 2, 3], Len=[1, 2, 3, 4] -> Exp: 4
    cout << "Case 3: " << get_ans(4, {1, 2, 2, 3}, {1, 2, 3, 4}) << " (Expected: 4)" << endl;

    return 0;
}
// #pragma GCC optimize("O3")
// #pragma GCC target("avx2")
// #pragma GCC optimize("unroll-loops")
#include "bits/stdc++.h"

// using namespace __gnu_pbds;
using namespace std;

#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll INF = 1e18 - 1, MOD = 1e9 + 7, MOD2 = 1e9 + 9, N = 1e5 + 1, MAXN = 1e6 + 1;
const int INFi = 1e9 + 100;
const ld EPS = 1e-12, PI = acos(-1);

random_device rd;
mt19937_64 rnd(rd());

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int cnt1 = 0, cnt0 = 0;
    for (int i = 0; i < n; i++) {
        cnt1 += (s[i] == '1');
        cnt0 += (s[i] == '0');
    }
    if (cnt1 != cnt0) {
        cout << "-1\n";
        return;
    }
    vector<int> ans;
    deque<int> dq;
    for (char &e : s) {
        dq.push_back(e - '0');
    }
    int d = 0;
    while (!dq.empty()) {
        if (dq.front() == dq.back()) {
            if (dq.front() == 1) {
                dq.push_front(1);
                dq.push_front(0);
                ans.push_back(d);
            } else {
                dq.push_back(0);
                dq.push_back(1);
                ans.push_back(n - d);
            }
            n += 2;
        }
        while (!dq.empty() && dq.front() != dq.back()) {
            dq.pop_back();
            dq.pop_front();
            d++;
        }
    }
    cout << (int)ans.size() << '\n';
    for (int &e : ans) {
        cout << e << ' ';
    } cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
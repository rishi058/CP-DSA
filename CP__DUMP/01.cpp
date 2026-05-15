#pragma GCC optimize("O3,unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void ins(vector<pair<int, int>>& v, int r, int i) {
    for (const auto& p : v) {
        if (p.first >= r && p.second <= i) return;
    }
    
    vector<pair<int, int>> nxt;
    nxt.reserve(v.size() + 1);
    bool add = false;
    
    for (const auto& p : v) {
        if (p.first <= r && p.second >= i) continue;
        
        if (!add && p.first > r) {
            nxt.push_back({r, i});
            add = true;
        }
        nxt.push_back(p);
    }
    
    if (!add) nxt.push_back({r, i});
    v = move(nxt);
}

int solve(int n, int m, int b, vector<int>& l, vector<int>& r, vector<int>& c) {
    struct I {
        int l, r, c;
        bool operator<(const I& o) const {
            if (l != o.l) return l < o.l;
            if (r != o.r) return r > o.r;
            return c < o.c;
        }
    };
    
    vector<I> iv(n);
    for (int i = 0; i < n; ++i) {
        iv[i].l = min(l[i], m);
        iv[i].r = min(r[i], m);
        iv[i].c = c[i];
    }
    sort(iv.begin(), iv.end());
    
    vector<vector<pair<int, int>>> dp(b + 1);
    dp[0].push_back({0, 0});
    
    vector<pair<int, int>> ns;
    ns.reserve(10);
    int mc = 0;
    
    for (int i = 0; i < n; ++i) {
        if (iv[i].c > b) continue;
        int cc = iv[i].c, il = iv[i].l, ir = iv[i].r;
        int lim = min(b - cc, mc);
        int nm = mc;
        
        for (int cst = lim; cst >= 0; --cst) {
            if (dp[cst].empty()) continue;
            
            ns.clear();
            for (const auto& s : dp[cst]) {
                if (s.first >= il) {
                    ns.push_back({max(s.first, ir), s.second + 1});
                }
            }
            
            if (!ns.empty()) {
                int tc = cst + cc;
                nm = max(nm, tc);
                for (const auto& s : ns) {
                    ins(dp[tc], s.first, s.second);
                }
            }
        }
        mc = nm;
    }
    
    int ans = 1e9;
    for (const auto& s : dp[b]) {
        if (s.first >= m) ans = min(ans, s.second);
    }
    
    return ans == 1e9 ? -1 : ans;
}

int main() {
    int n1 = 4, m1 = 10, b1 = 15;
    vector<int> l1 = {0, 4, 0, 5}, r1 = {5, 10, 10, 10}, c1 = {10, 5, 20, 5};
    cout << solve(n1, m1, b1, l1, r1, c1) << "\n";
    
    int n2 = 3, m2 = 8, b2 = 12;
    vector<int> l2 = {0, 3, 0}, r2 = {4, 8, 8}, c2 = {4, 8, 12};
    cout << solve(n2, m2, b2, l2, r2, c2) << "\n";
    
    int n3 = 3, m3 = 5, b3 = 10;
    vector<int> l3 = {0, 2, 4}, r3 = {3, 5, 5}, c3 = {4, 5, 5};
    cout << solve(n3, m3, b3, l3, r3, c3) << "\n";
    
    return 0;
}
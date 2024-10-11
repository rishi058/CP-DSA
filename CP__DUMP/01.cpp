#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPlace(const vector<pair<int, int>>& ivls, int n, int d) {
    int pos = ivls[0].first, cnt = 1;

    for (int i = 1; i < n; i++) {
        int a = ivls[i].first, b = ivls[i].second;

        if (pos + d <= b) {
            pos = max(a, pos + d);
            cnt++;
        }

        if (cnt >= n)
            return true;
    }

    return cnt >= n;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> ivls(n);

    for (int i = 0; i < n; i++)
        cin >> ivls[i].first >> ivls[i].second;

    sort(ivls.begin(), ivls.end());

    int lo = 0, hi = ivls.back().second - ivls[0].first, res = 0;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (canPlace(ivls, n, mid)) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << res << endl;
    return 0;
}

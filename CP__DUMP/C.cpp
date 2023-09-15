/*
void solve() {
    ll j, pos = -1;
    string sop;
    cin >> j >> sop;
    rep(i, 0, j) {
        if (sop[i] == '1') {
            pos = i;
            break;
        }
    }
    // dbgs(pos)
    if (pos == -1  pos == (j - 1)  pos == (j - 2)) {
        cout << sop << '\n';
    } else {
        rep(i, 0, pos) cout << 0;
        cout << 1;
        rep(i, pos + 1, j) cout << 0;
        cout << '\n';
    }
}

int main() {
    fast_io;
    ll thhh = 1;
    cin >> thhh;
    while (thhh--) {
        solve();
    }
    return 0;
}
*/
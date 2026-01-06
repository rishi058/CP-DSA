#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

map<ll, ll> mp;

ll f(ll k, int m, const vector<int>& a) {
    if (k == 0) return 1;
    if (mp.count(k)) return mp[k];
    
    ll res = 0;
    for (int i = 0; i < m; i++) {
        res += f(k / a[i], m, a);
    }
    return mp[k] = res;
}

int main() {
    ll n = 5;
    int m = 2;
    vector<int> a = {2, 3};

    mp.clear();
    cout << "Test Case 1 (N=5, M=2, A={2,3}): " << f(n, m, a) << endl;

    n = 2; m = 2; a = {2, 2};
    mp.clear();
    cout << "Test Case 2 (N=2, M=2, A={2,2}): " << f(n, m, a) << endl;

    n = 3; m = 3; a = {2, 3, 3};
    mp.clear();
    cout << "Test Case 3 (N=3, M=3, A={2,3,3}): " << f(n, m, a) << endl;

    return 0;
}
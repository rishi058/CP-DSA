#include <bits/stdc++.h>
// #include <vector>
// #include <set>
// #include <queue>
// #include <algorithm>

using namespace std;

int findMinimumCost(int n, vector<int> from, vector<int> to) {
    vector<vector<int>> adj(n + 1);
    for (size_t i = 0; i < from.size(); ++i) {
        adj[from[i]].push_back(to[i]);
        adj[to[i]].push_back(from[i]);
    }
    for (int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    set<int> unvis;
    for (int i = 1; i <= n; ++i) {
        unvis.insert(i);
    }

    int comps = 0;
    while (!unvis.empty()) {
        comps++;
        int start = *unvis.begin();
        unvis.erase(unvis.begin());
        
        queue<int> q;
        q.push(start);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            auto it = unvis.begin();
            while (it != unvis.end()) {
                int v = *it;
                if (binary_search(adj[u].begin(), adj[u].end(), v)) {
                    ++it;
                } else {
                    q.push(v);
                    it = unvis.erase(it);
                }
            }
        }
    }
    return comps - 1;
}

int main() {
    int n1 = 4;
    vector<int> f1 = {1, 3, 2, 4, 4};
    vector<int> t1 = {2, 1, 3, 2, 3};
    cout << findMinimumCost(n1, f1, t1) << "\n";

    int n2 = 4;
    vector<int> f2 = {1, 2, 3, 4};
    vector<int> t2 = {2, 3, 1, 3};
    cout << findMinimumCost(n2, f2, t2) << "\n";

    int n3 = 5;
    vector<int> f3 = {1, 3, 1, 4};
    vector<int> t3 = {3, 5, 2, 3};
    cout << findMinimumCost(n3, f3, t3) << "\n";

    return 0;
}
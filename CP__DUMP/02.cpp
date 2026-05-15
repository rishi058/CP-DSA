#include <bits/stdc++.h>


using namespace std;

vector<int> findKthNextHigherDemandLevels(vector<int> demandLevels, int k) {
    int n = demandLevels.size();
    vector<int> res(n, -1);
    vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> pqs(k + 1);

    for (int i = 0; i < n; ++i) {
        int val = demandLevels[i];
        
        for (int j = k; j >= 1; --j) {
            while (!pqs[j].empty() && pqs[j].top().first < val) {
                pair<int, int> p = pqs[j].top();
                pqs[j].pop();
                
                if (j == k) {
                    res[p.second] = i + 1;
                } else {
                    pqs[j + 1].push(p);
                }
            }
        }
        pqs[1].push({val, i});
    }
    
    return res;
}

void runTest(vector<int> arr, int k) {
    vector<int> ans = findKthNextHigherDemandLevels(arr, k);
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    runTest({1, 4, 2, 5, 3}, 2);
    
    runTest({3, 4, 2, 6, 5}, 2);
    
    runTest({3, 1, 2, 4, 5}, 2);
    
    return 0;
}
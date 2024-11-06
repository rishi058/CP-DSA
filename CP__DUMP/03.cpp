#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;


int inf = 1e9+7;

// Function to calculate collision time between two cars
double getCollisionTime(pair<int, int> a, pair<int, int> b) {
    int posDiff = b.first - a.first, velDiff = a.second - b.second;
    return (velDiff == 0 || posDiff * velDiff <= 0) ? inf : double(posDiff) / velDiff;
}

int main() {
    int n, M;
    cin >> n >> M;
    vector<pair<int, int>> cars(n);
    for (auto &car : cars) cin >> car.first >> car.second;

    priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> pq;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            pq.push({getCollisionTime(cars[i], cars[j]), {i, j}});

    vector<bool> removed(n, false);
    while (!pq.empty() && M > 0) {
        auto [time, carsPair] = pq.top(); pq.pop();
        auto [i, j] = carsPair;
        if (!removed[i] && !removed[j]) removed[i] = true, M--;
    }

    double maxTime = inf;
    for (int i = 0; i < n; ++i) if (!removed[i])
        for (int j = i + 1; j < n; ++j) if (!removed[j])
            maxTime = min(maxTime, getCollisionTime(cars[i], cars[j]));

    
	if(maxTime==inf){cout << -1 << endl; return 0;}
	int ans = maxTime*100000;
	cout<<ans<<"\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// T.C --> BELL NUMBERS

void printPartition(const vector<vector<int>>& partition) {
    cout << "{ ";
    for (const auto& subset : partition) {
        cout << "{ ";
        for (const auto& num : subset) {
            cout << num << " ";
        }
        cout << "} ";
    }
    cout << "}\n" << endl;
}

void generatePartitions(const vector<int>& nums, vector<vector<int>>& partition, int index) {
    if (index == nums.size()) {
        printPartition(partition);
        return;
    }

    for (int i = 0; i < partition.size(); i++) {
        partition[i].push_back(nums[index]);
        generatePartitions(nums, partition, index + 1);
        partition[i].pop_back();
    }

    partition.push_back({nums[index]});
    generatePartitions(nums, partition, index + 1);
    partition.pop_back();
}


int main() {
    vector<int> nums = {1,2,3,4};
    vector<vector<int>> partition;
    generatePartitions(nums, partition, 0);
    return 0;
}

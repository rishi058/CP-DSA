#include <bits/stdc++.h>
using namespace std;

// total count of partition --> BELL NUMBERS
// Time complexity is b/w O(B(n)*n) & O(n!)

int tot = 0;

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
        tot++;
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
    // for n = 10, it generates effeciently in time 300ms.
    // for n = 11, it takes 2000ms.
    // for n = 12, dont work.

    vector<int> nums = {1,2,3,4,5};
    vector<vector<int>> partition;
    generatePartitions(nums, partition, 0);
    cout<<tot<<" ";
    return 0;
}

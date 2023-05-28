#include <iostream>
#include <vector>

using namespace std;

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

void generatePartitionsHelper(const vector<int>& nums, vector<vector<int>>& partition, vector<int>& currentPartition, int index) {
    if (index == nums.size()) {
        printPartition(partition);
        return;
    }

    for (size_t i = 0; i < partition.size(); i++) {
        partition[i].push_back(nums[index]);
        generatePartitionsHelper(nums, partition, currentPartition, index + 1);
        partition[i].pop_back();
    }

    vector<int> newSubset;
    newSubset.push_back(nums[index]);
    partition.push_back(newSubset);
    generatePartitionsHelper(nums, partition, currentPartition, index + 1);
    partition.pop_back();
}

void generatePartitions(const vector<int>& nums) {
    vector<vector<int>> partition;
    vector<int> currentPartition;
    generatePartitionsHelper(nums, partition, currentPartition, 0);
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    generatePartitions(nums);

    return 0;
}

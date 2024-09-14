#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<pair<int, int>> findZeroSumSubarrays(vector<int>& arr) {
    unordered_map<int, vector<int>> prefixSumMap;
    vector<pair<int, int>> result;
    int prefixSum = 0;

    prefixSumMap[0].push_back(-1);

    for (int i = 0; i < arr.size(); ++i) {
        prefixSum += arr[i];

        if (prefixSumMap.find(prefixSum) != prefixSumMap.end()) {
            for (auto startIdx : prefixSumMap[prefixSum]) {
                result.push_back({startIdx + 1, i});
            }
        }
        prefixSumMap[prefixSum].push_back(i);
    }

    return result;
}

int main() {
    vector<int> arr = {1, 2, -3, 3, -1, 2};
    vector<pair<int, int>> subarrays = findZeroSumSubarrays(arr);

    for (auto& p : subarrays) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }

    return 0;
}

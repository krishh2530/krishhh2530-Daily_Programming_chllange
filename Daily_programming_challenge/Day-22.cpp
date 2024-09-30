#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int findFirstKTimes(const vector<int>& arr, int k) {
    unordered_map<int, int> freqMap;

    for (int num : arr) {
        freqMap[num]++;
    }

    for (int num : arr) {
        if (freqMap[num] == k) {
            return num;
        }
    }

    return -1;
}

int main() {
    vector<int> arr1 = {3, 1, 4, 4, 5, 2, 6, 1, 4};
    int k1 = 2;
    cout << "Output: " << findFirstKTimes(arr1, k1) << endl;

    vector<int> arr2 = {2, 3, 4, 2, 2, 5, 5};
    int k2 = 2;
    cout << "Output: " << findFirstKTimes(arr2, k2) << endl;

    vector<int> arr3 = {1, 1, 1, 1};
    int k3 = 1;
    cout << "Output: " << findFirstKTimes(arr3, k3) << endl;

    vector<int> arr4 = {10};
    int k4 = 1;
    cout << "Output: " << findFirstKTimes(arr4, k4) << endl;

    vector<int> arr5 = {6, 6, 6, 6, 7, 7, 8, 8, 8};
    int k5 = 3;
    cout << "Output: " << findFirstKTimes(arr5, k5) << endl;

    return 0;
}

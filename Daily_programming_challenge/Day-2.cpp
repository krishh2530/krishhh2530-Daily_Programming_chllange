#include <iostream>
#include <vector>
using namespace std;

int findMissingNumber(const vector<int>& arr) {
    int n = arr.size() + 1;
    int totalSum = n * (n + 1) / 2;
    int arrSum = 0;
    
    for (int num : arr) {
        arrSum += num;
    }
    
    return totalSum - arrSum;
}

int main() {
    vector<int> arr1 = {1, 2, 4, 5};
    cout << "Missing number: " << findMissingNumber(arr1) << endl;

    vector<int> arr2 = {2, 3, 4, 5};
    cout << "Missing number: " << findMissingNumber(arr2) << endl;

    vector<int> arr3 = {1, 2, 3, 4};
    cout << "Missing number: " << findMissingNumber(arr3) << endl;

    vector<int> arr4 = {1};
    cout << "Missing number: " << findMissingNumber(arr4) << endl;

    vector<int> arr5(999999);
    for (int i = 0; i < 999999; ++i) {
        arr5[i] = i + 1;
    }
    cout << "Missing number: " << findMissingNumber(arr5) << endl;

    return 0;
}

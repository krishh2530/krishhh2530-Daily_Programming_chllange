#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if (n < 3) return 0;

    vector<int> leftMax(n), rightMax(n);

    leftMax[0] = height[0];
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    int trappedWater = 0;
    for (int i = 0; i < n; i++) {
        trappedWater += min(leftMax[i], rightMax[i]) - height[i];
    }

    return trappedWater;
}

int main() {
    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> height2 = {4, 2, 0, 3, 2, 5};
    vector<int> height3 = {1, 1, 1};
    vector<int> height4 = {5};
    vector<int> height5 = {2, 0, 2};

    cout << "Test case 1: " << trap(height1) << endl;
    cout << "Test case 2: " << trap(height2) << endl;
    cout << "Test case 3: " << trap(height3) << endl;
    cout << "Test case 4: " << trap(height4) << endl;
    cout << "Test case 5: " << trap(height5) << endl;

    return 0;
}

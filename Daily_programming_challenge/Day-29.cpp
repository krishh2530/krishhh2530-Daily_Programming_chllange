#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long fibonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        vector<long long> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "The " << n << "-th Fibonacci number is: " << solution.fibonacci(n) << endl;

    return 0;
}

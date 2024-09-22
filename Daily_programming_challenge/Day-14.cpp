#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int countSubstringsWithKDistinct(string s, int k) {
    int n = s.length();
    int result = 0;
    unordered_map<char, int> charCount;
    int left = 0, right = 0, distinctCount = 0;

    for (right = 0; right < n; ++right) {
        charCount[s[right]]++;
        if (charCount[s[right]] == 1) {
            distinctCount++;
        }

        while (distinctCount > k) {
            charCount[s[left]]--;
            if (charCount[s[left]] == 0) {
                distinctCount--;
            }
            left++;
        }

        result += right - left + 1;
    }

    return result;
}

int main() {
    string s1 = "pqpqs";
    int k1 = 2;
    cout << "Result: " << countSubstringsWithKDistinct(s1, k1) << endl;

    string s2 = "aabacbebebe";
    int k2 = 3;
    cout << "Result: " << countSubstringsWithKDistinct(s2, k2) << endl;

    string s3 = "a";
    int k3 = 1;
    cout << "Result: " << countSubstringsWithKDistinct(s3, k3) << endl;

    string s4 = "abc";
    int k4 = 3;
    cout << "Result: " << countSubstringsWithKDistinct(s4, k4) << endl;

    return 0;
}

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndex;
    int maxLength = 0;
    int start = 0;

    for (int end = 0; end < s.length(); end++) {
        char currentChar = s[end];

        // If the character is already in the map, move the start to the right of the previous index of the character
        if (charIndex.find(currentChar) != charIndex.end() && charIndex[currentChar] >= start) {
            start = charIndex[currentChar] + 1;
        }

        // Update the index of the current character
        charIndex[currentChar] = end;

        // Calculate the length of the current window and update maxLength
        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}

int main() {
    // Test cases
    string s1 = "abcabcbb";
    string s2 = "bbbbb";
    string s3 = "pwwkew";
    string s4 = "abcdefgh";
    string s5 = "a";

    cout << lengthOfLongestSubstring(s1) << endl; // Output: 3
    cout << lengthOfLongestSubstring(s2) << endl; // Output: 1
    cout << lengthOfLongestSubstring(s3) << endl; // Output: 3
    cout << lengthOfLongestSubstring(s4) << endl; // Output: 8
    cout << lengthOfLongestSubstring(s5) << endl; // Output: 1

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

string expandAroundCenter(const string& s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(string s) {
    if (s.empty()) return "";
    
    string longest;
    
    for (int i = 0; i < s.length(); i++) {
        string oddPalindrome = expandAroundCenter(s, i, i);   
        string evenPalindrome = expandAroundCenter(s, i, i+1); 
        
        if (oddPalindrome.length() > longest.length()) {
            longest = oddPalindrome;
        }
        if (evenPalindrome.length() > longest.length()) {
            longest = evenPalindrome;
        }
    }
    
    return longest;
}

int main() {
    string s1 = "babad";
    cout << "Longest Palindromic Substring: " << longestPalindrome(s1) << endl;

    string s2 = "cbbd";
    cout << "Longest Palindromic Substring: " << longestPalindrome(s2) << endl;

    string s3 = "a";
    cout << "Longest Palindromic Substring: " << longestPalindrome(s3) << endl;

    string s4 = "aaaa";
    cout << "Longest Palindromic Substring: " << longestPalindrome(s4) << endl;

    string s5 = "abc";
    cout << "Longest Palindromic Substring: " << longestPalindrome(s5) << endl;

    return 0;
}

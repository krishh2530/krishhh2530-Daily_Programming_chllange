#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
        return "";
    }
    
    string prefix = strs[0];
    
    for (int i = 1; i < strs.size(); i++) {
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.length() - 1);
            if (prefix.empty()) {
                return "";
            }
        }
    }
    
    return prefix;
}

int main() {
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs1) << endl;

    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs2) << endl;

    vector<string> strs3 = {"apple", "ape", "april"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs3) << endl;

    vector<string> strs4 = {""};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs4) << endl;

    vector<string> strs5 = {"alone"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs5) << endl;

    return 0;
}

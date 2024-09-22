#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramGroups;
    
    for (string& str : strs) {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        anagramGroups[sortedStr].push_back(str);
    }
    
    vector<vector<string>> result;
    for (auto& group : anagramGroups) {
        result.push_back(group.second);
    }
    
    return result;
}

int main() {
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result1 = groupAnagrams(strs1);
    for (auto& group : result1) {
        for (auto& str : group) {
            cout << str << " ";
        }
        cout << endl;
    }

    vector<string> strs2 = {""};
    vector<vector<string>> result2 = groupAnagrams(strs2);
    for (auto& group : result2) {
        for (auto& str : group) {
            cout << str << " ";
        }
        cout << endl;
    }

    vector<string> strs3 = {"a"};
    vector<vector<string>> result3 = groupAnagrams(strs3);
    for (auto& group : result3) {
        for (auto& str : group) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}

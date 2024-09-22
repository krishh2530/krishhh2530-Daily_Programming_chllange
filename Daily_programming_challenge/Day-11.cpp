#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<string> permuteUnique(string s) {
    sort(s.begin(), s.end());
    vector<string> result;
    do {
        result.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    return result;
}

int main() {
    string s1 = "abc";
    vector<string> result1 = permuteUnique(s1);
    for (string& perm : result1) {
        cout << perm << " ";
    }
    cout << endl;

    string s2 = "aab";
    vector<string> result2 = permuteUnique(s2);
    for (string& perm : result2) {
        cout << perm << " ";
    }
    cout << endl;

    string s3 = "aaa";
    vector<string> result3 = permuteUnique(s3);
    for (string& perm : result3) {
        cout << perm << " ";
    }
    cout << endl;

    string s4 = "abcd";
    vector<string> result4 = permuteUnique(s4);
    for (string& perm : result4) {
        cout << perm << " ";
    }
    cout << endl;

    return 0;
}

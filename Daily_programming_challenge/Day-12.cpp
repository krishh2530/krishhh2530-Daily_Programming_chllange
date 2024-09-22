#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

bool isValid(string s) {
    stack<char> stk;
    unordered_map<char, char> bracketPairs = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    
    for (char& ch : s) {
        if (bracketPairs.count(ch)) {
            if (stk.empty() || stk.top() != bracketPairs[ch]) {
                return false;
            }
            stk.pop();
        } else {
            stk.push(ch);
        }
    }
    
    return stk.empty();
}

int main() {
    string s1 = "()";
    cout << (isValid(s1) ? "true" : "false") << endl;

    string s2 = "([)]";
    cout << (isValid(s2) ? "true" : "false") << endl;

    string s3 = "[{()}]";
    cout << (isValid(s3) ? "true" : "false") << endl;

    string s4 = "";
    cout << (isValid(s4) ? "true" : "false") << endl;

    string s5 = "{[}";
    cout << (isValid(s5) ? "true" : "false") << endl;

    return 0;
}

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int evaluatePostfix(const string &expression) {
    stack<int> st;
    istringstream iss(expression);
    string token;

    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            
            if (token == "+")
                st.push(a + b);
            else if (token == "-")
                st.push(a - b);
            else if (token == "*")
                st.push(a * b);
            else if (token == "/")
                st.push(a / b);
        } else {
            st.push(stoi(token));
        }
    }

    return st.top();
}

int main() {
    vector<string> testCases = {
        "2 1 + 3 *",
        "5 6 +",
        "-5 6 -",
        "15 7 1 1 + - / 3 * 2 1 1 + + -",
        "5"
    };

    for (const auto &expr : testCases) {
        cout << "Input: " << expr << "\n";
        cout << "Output: " << evaluatePostfix(expr) << "\n\n";
    }

    return 0;
}

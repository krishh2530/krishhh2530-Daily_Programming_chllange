#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

string reverseWords(string s) {
    stringstream ss(s);
    string word;
    vector<string> words;

    while (ss >> word) {
        words.push_back(word);
    }

    string result;
    for (int i = words.size() - 1; i >= 0; --i) {
        result += words[i];
        if (i > 0) {
            result += " ";
        }
    }

    return result;
}

int main() {
    string s1 = "the sky is blue";
    string s2 = "  hello world  ";
    string s3 = "a good   example";
    string s4 = "    ";
    string s5 = "word";

    cout << "\"" << reverseWords(s1) << "\"" << endl;
    cout << "\"" << reverseWords(s2) << "\"" << endl;
    cout << "\"" << reverseWords(s3) << "\"" << endl;
    cout << "\"" << reverseWords(s4) << "\"" << endl;
    cout << "\"" << reverseWords(s5) << "\"" << endl;

    return 0;
}

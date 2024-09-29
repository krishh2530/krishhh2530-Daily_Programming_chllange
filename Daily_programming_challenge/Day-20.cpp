#include <iostream>
#include <stack>

using namespace std;

void insertSorted(stack<int> &st, int element) {
    if (st.empty() || st.top() <= element) {
        st.push(element);
        return;
    }
    
    int topElement = st.top();
    st.pop();
    insertSorted(st, element);
    st.push(topElement);
}

void sortStack(stack<int> &st) {
    if (st.empty() || st.size() == 1) {
        return;
    }

    int topElement = st.top();
    st.pop();
    sortStack(st);
    insertSorted(st, topElement);
}

void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;

    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    cout << "Stack before sorting: ";
    printStack(st);

    sortStack(st);

    cout << "Stack after sorting: ";
    printStack(st);

    return 0;
}

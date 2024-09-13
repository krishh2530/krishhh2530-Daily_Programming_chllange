#include <iostream>
#include <vector>
using namespace std;

vector<int> findLeaders(vector<int>& arr) {
    int n = arr.size();
    vector<int> leaders;
    int maxFromRight = arr[n - 1]; 
    

    leaders.push_back(maxFromRight);
    
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > maxFromRight) {
            leaders.push_back(arr[i]);
            maxFromRight = arr[i];
        }
    }
    
    reverse(leaders.begin(), leaders.end());
    
    return leaders;
}

int main() {
    vector<int> arr1 = {16, 17, 4, 3, 5, 2};
    vector<int> leaders1 = findLeaders(arr1);
    cout << "Leaders: ";
    for (int leader : leaders1) {
        cout << leader << " ";
    }
    cout << endl

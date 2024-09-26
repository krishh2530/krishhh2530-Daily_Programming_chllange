#include <iostream>
#include <cmath>
using namespace std;

int countDivisors(int N) {
    int count = 0;
    for (int i = 1; i <= sqrt(N); i++) {
        if (N % i == 0) {
            count++;
            if (i != N / i) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int N;
    cin >> N;
    cout << countDivisors(N) << endl;
    return 0;
}

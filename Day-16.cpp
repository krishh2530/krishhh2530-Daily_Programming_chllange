#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long N, long long M) {
    return (N / gcd(N, M)) * M;
}

int main() {
    long long N1 = 4, M1 = 6;
    long long N2 = 5, M2 = 10;
    long long N3 = 7, M3 = 3;
    long long N4 = 1, M4 = 987654321;
    long long N5 = 123456, M5 = 789012;

    cout << lcm(N1, M1) << endl;
    cout << lcm(N2, M2) << endl;
    cout << lcm(N3, M3) << endl;
    cout << lcm(N4, M4) << endl;
    cout << lcm(N5, M5) << endl;

    return 0;
}

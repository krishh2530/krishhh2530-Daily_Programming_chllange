#include <iostream>
#include <vector>
using namespace std;

vector<long long> primeFactorization(long long N) {
    vector<long long> factors;
    for (long long i = 2; i * i <= N; i++) {
        while (N % i == 0) {
            factors.push_back(i);
            N /= i;
        }
    }
    if (N > 1) {
        factors.push_back(N);
    }
    return factors;
}

int main() {
    long long N1 = 30;
    long long N2 = 49;
    long long N3 = 19;
    long long N4 = 64;
    long long N5 = 123456;

    vector<long long> result1 = primeFactorization(N1);
    vector<long long> result2 = primeFactorization(N2);
    vector<long long> result3 = primeFactorization(N3);
    vector<long long> result4 = primeFactorization(N4);
    vector<long long> result5 = primeFactorization(N5);

    for (long long r : result1) cout << r << " "; cout << endl;
    for (long long r : result2) cout << r << " "; cout << endl;
    for (long long r : result3) cout << r << " "; cout << endl;
    for (long long r : result4) cout << r << " "; cout << endl;
    for (long long r : result5) cout << r << " "; cout << endl;

    return 0;
}

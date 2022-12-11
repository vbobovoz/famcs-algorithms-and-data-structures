#include <iostream>
using namespace std;

unsigned long long mod_pow(unsigned long long base, unsigned long long exp) {
    unsigned long long res = 1;
    int modulus = 1000000007;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % modulus;
        }
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    unsigned long long num = 1;
    for(int i = n - k + 1; i <= n; ++i) {
        num = (num * i) % 1000000007;
    }
    unsigned long long den = 1;
    for(int i = 1; i <= k; ++i) {
        den = (den * i) % 1000000007;
    }
    cout << (num * mod_pow(den, 1000000005)) % 1000000007;
}
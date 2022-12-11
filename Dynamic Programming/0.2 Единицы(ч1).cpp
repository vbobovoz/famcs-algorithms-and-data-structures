#include <iostream>
using namespace std;

long long C(int n, int k) {
    long long **arr = new long long*[n + 1];
    for (int i = 0; i <= n; ++i) {
        arr[i] = new long long[n + 1];
    }
    for(int i = 0; i <= n; ++i) {
        arr[i][0] = 1;
        arr[i][i] = 1;
        for(int j = 1; j < i; ++j) {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            arr[i][j] %= 1000000007;
        }
    }
    return arr[n][k];
}

int main(){
    int n, k;
    cin >> n >> k;
    cout << C(n, k);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e4;

using matrix = vector<vector<int>>;

matrix multiply(const matrix& a, const matrix& b) {
    matrix ret(2, vector<int>(2));
    ret[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD;
    ret[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD;
    ret[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD;
    ret[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD;
    return ret;
}

int fib(int n) {
    matrix A = { {1, 1}, {1, 0} };
    matrix B = { {1, 0}, {0, 1} };
    int exp = n;
    while (exp > 0) {
        if (exp & 1) {
            B = multiply(A, B);
        }
        exp >>= 1;
        A = multiply(A, A);
    }
    return B[1][0] % MOD;
}

int main() {
    int n;
    while (scanf("%d", &n) && (n + 1)) {
        printf("%d\n", fib(n));
    }
    return 0;
}

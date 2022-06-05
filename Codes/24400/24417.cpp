#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

typedef long long ll;
typedef vector<vector<ll>> matrix;

matrix multiply(const matrix& a, const matrix& b) {
    matrix ret(2, vector<ll>(2));
    ret[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD;
    ret[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD;
    ret[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD;
    ret[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD;
    return ret;
}

int fib_calls(int n) {
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
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    cout << fib_calls(n) << ' ' << n - 2;
    return 0;
}

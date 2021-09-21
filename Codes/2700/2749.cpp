#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<int>> Matrix;

const int MOD = 1000000;

Matrix matmul(Matrix A, Matrix B) {
    Matrix ret(A.size(), vector<int>(A.size()));
    for (int i = 0; i < (int) A.size(); ++i) {
        for (int j = 0; j < (int) B.size(); ++j) {
            for (int k = 0; k < (int) A.size(); ++k) {
                ret[i][j] = (ret[i][j] + (ll) A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return ret;
}

Matrix pow(Matrix M, ll exponent) {
    Matrix result = {{1, 0}, {0, 1}};
    while (exponent > 0) {
        if (exponent & 1) {
            result = matmul(M, result);
        }
        exponent >>= 1;
        M = matmul(M, M);
    }
    return result;
}

int main() {
    ll n;
    cin >> n;

    Matrix A = {{1, 1}, {1, 0}};
    Matrix result = pow(A, n);
    cout << result[1][0];
    return 0;
}

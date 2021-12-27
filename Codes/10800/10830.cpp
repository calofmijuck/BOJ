#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<int>> Matrix;

const int MOD = 1000;

Matrix I;

Matrix matmul(Matrix A, Matrix B) {
    Matrix ret(A.size(), vector<int>(A.size()));
    for (int i = 0; i < (int) A.size(); ++i) {
        for (int j = 0; j < (int) B.size(); ++j) {
            for (int k = 0; k < (int) A.size(); ++k) {
                ret[i][j] = (ret[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return ret;
}

Matrix pow(Matrix m, ll k) {
    if (k == 0) {
        return I;
    } else if (k == 1) {
        return m;
    } else if (k % 2 == 0) {
        return pow(matmul(m, m), k / 2);
    } else {
        return matmul(m, pow(m, k - 1));
    }
}

void generate_identity_matrix(int n) {
    I.resize(n);
    for (int i = 0; i < n; ++i) {
        I[i].resize(n);
        I[i][i] = 1;
    }
}

int main() {
    int n;
    ll k;
    cin >> n >> k;

    generate_identity_matrix(n);

    Matrix matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    Matrix result = pow(matrix, k);
    for (vector<int> row : result) {
        for (int e : row) {
            cout << e % MOD << ' ';
        }
        cout << '\n';
    }
    return 0;
}

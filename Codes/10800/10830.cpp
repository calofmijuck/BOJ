#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int> > Matrix;
typedef long long ll;

const int MOD = 1000;
Matrix mat;
Matrix I;

Matrix matmul(Matrix A, Matrix B) {
    Matrix ret;
    ret.resize(A.size());
    for(int i = 0; i < ret.size(); ++i) {
        ret[i].resize(A.size());
    }
    for(int i = 0; i < A.size(); ++i) {
        for(int j = 0; j < B.size(); ++j) {
            for(int k = 0; k < A.size(); ++k) {
                ret[i][j] = (ret[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return ret;
}

Matrix pow(Matrix mat, ll k) {
    if(k == 0) {
        return I;
    } else if(k == 1) {
        return mat;
    } else if(k % 2 == 0) {
        return pow(matmul(mat, mat), k / 2);
    } else {
        return matmul(mat, pow(mat, k - 1));
    }
}

int main() {
    int n, x;
    ll k;
    cin >> n >> k;
    mat.resize(n);
    I.resize(n);
    for(int i = 0; i < n; ++i) {
        I[i].resize(n);
        I[i][i] = 1;
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> x;
            mat[i].push_back(x % MOD);
        }
    }
    Matrix ret = pow(mat, k);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) printf("%d ", ret[i][j] % MOD);
        puts("");
    }
}

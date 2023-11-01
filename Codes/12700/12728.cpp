#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> matrix;

const int MOD = 1000;

matrix identity = { {1, 0}, {0, 1} };

matrix start = { {6}, {2} };
matrix A = { {6, -4}, {1, 0} };

matrix multiply(matrix& a, matrix& b) {
    int N = a.size();
    int K = a[0].size();
    int M = b[0].size();

    matrix result(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int sum = 0;
            for (int k = 0; k < K; ++k) {
                sum = (sum + a[i][k] * b[k][j]) % MOD;
            }
            if (sum < 0) {
                sum += MOD;
            }
            result[i][j] = sum;
        }
    }
    return result;
}

matrix exponentiate(matrix a, int exponent) {
    matrix result = identity;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = multiply(result, a);
        }
        a = multiply(a, a);
        exponent >>= 1;
    }
    return result;
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; ++t) {
        int n;
        scanf("%d", &n);

        matrix coefficient = exponentiate(A, n - 1);
        matrix result = multiply(coefficient, start);
        printf("Case #%d: %03d\n", t, result[0][0] - 1);
    }
    return 0;
}

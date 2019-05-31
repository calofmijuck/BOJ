#include <bits/stdc++.h>
using namespace std;
#define MOD 10000

int fib(int n) {
    int A[2][2] = {1, 1, 1, 0}, B[2][2] = {1, 0, 0, 1}, tmp[2][2];
    int exp = n;
    while(exp > 0) {
        if(exp & 1) {
            tmp[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD;
            tmp[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD;
            tmp[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD;
            tmp[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD;
            for(int i = 0; i < 2; ++i) {
                for(int j = 0; j < 2; ++j) B[i][j] = tmp[i][j];
            }
        }
        exp >>= 1;
        tmp[0][0] = (A[0][0] * A[0][0] + A[0][1] * A[1][0]) % MOD;
        tmp[0][1] = (A[0][0] * A[0][1] + A[0][1] * A[1][1]) % MOD;
        tmp[1][0] = (A[1][0] * A[0][0] + A[1][1] * A[1][0]) % MOD;
        tmp[1][1] = (A[1][0] * A[0][1] + A[1][1] * A[1][1]) % MOD;
        for(int i = 0; i < 2; ++i) {
            for(int j = 0; j < 2; ++j) A[i][j] = tmp[i][j];
        }
    }
    return B[1][0] % MOD;
}

int main() {
    int n;
    while(scanf("%d", &n) && (n + 1)) {
        printf("%d\n", fib(n));
    }
    return 0;
}

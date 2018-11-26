#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A[2][2] = {1, 1, 1, 0}, tmp[2][2], prod[2][2] = {1, 1, 1, 0}, MOD = 1000000007;

ll gcd(ll a, ll b) {
    if(a == 0) return b;
    else return gcd(b % a, a);
}

void matmul(ll* A, ll* B, ll* dst) {
    dst[0] = (A[0] * B[0] + A[1] * B[2]) % MOD;
    dst[1] = (A[0] * B[1] + A[1] * B[3]) % MOD;
    dst[2] = (A[2] * B[0] + A[3] * B[2]) % MOD;
    dst[3] = (A[2] * B[1] + A[3] * B[3]) % MOD;
}

void copy(ll* src, ll* dst) {
    for(int i = 0; i < 4; ++i) dst[i] = src[i];
}

void fib(ll g) {
    while(1) {
        if(g & 1) {
            matmul(&prod[0][0], &A[0][0], &tmp[0][0]);
            copy(&tmp[0][0], &prod[0][0]);
        }
        if((g >>= 1) == 0) break;
        matmul(&A[0][0], &A[0][0], &tmp[0][0]);
        copy(&tmp[0][0], &A[0][0]);
    }
}

int main() {
    ll n, m, g;
    scanf("%lld %lld", &n, &m);
    fib(gcd(n, m));
    printf("%lld", prod[1][1]);
    return 0;
}

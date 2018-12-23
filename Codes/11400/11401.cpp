#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll modinv(ll n, ll p) {
    ll prime = p - 2, prod = 1;
    while(1) {
        if(prime & 1) {
            prod *= n;
            prod %= p;
        }
        prime >>= 1;
        if(prime == 0) break;
        n *= n;
        n %= p;
    }
    return prod;
}

int main() {
    int n, r;
    scanf("%d %d", &n, &r);
    r = (n - r > r) ? r : n - r;
    ll prod = 1;
    for(int i = 1; i <= r; i++) prod = (prod * i) % MOD;
    int rfac = modinv(prod, MOD);
    for(int i = r + 1; i <= n - r; ++i) prod = (prod * i) % MOD;
    int n_rfac = modinv(prod, MOD);
    for(int i = n - r + 1; i <= n; ++i) prod = (prod * i) % MOD;
    printf("%lld", prod * rfac % MOD * n_rfac % MOD);
    return 0;
}

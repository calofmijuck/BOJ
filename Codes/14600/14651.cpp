#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 1000000009;

ll modpow(ll a, ll n) {
    if(n == 0) return 1;
    if(n == 1) return a;
    if(n & 1) {
        return a * modpow(a, n - 1) % MOD;
    } else {
        return modpow(a * a % MOD, n / 2) % MOD;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    if(n == 1) printf("0");
    else printf("%lld", (ll) 2 * modpow(3, n - 2) % MOD);
    return 0;
}

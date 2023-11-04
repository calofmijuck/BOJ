#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000000

typedef long long ll;

const int MOD = 1000000007;

int factorial[MAX_N + 2];
int powers_of_k[MAX_N + 1];

ll power(ll a, int n) {
    ll result = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        n >>= 1;
    }
    return result;
}

ll modular_inverse(ll a) {
    return power(a, MOD - 2);
}

int calculate(int n, int k) {
    ll result = 0;
    for (int i = (n + 1) / 2; i <= n; ++i) {
        int j = n - i;

        ll curr = (ll) (i - j + 1) * factorial[n] % MOD * powers_of_k[i] % MOD;
        curr = curr * modular_inverse((ll) factorial[i + 1] * factorial[j] % MOD) % MOD;
        result = (result + curr) % MOD;
    }
    return result;
}

void preprocess(int n, int k) {
    // factorials
    factorial[0] = 1;
    for (int i = 1; i <= n + 1; ++i) {
        factorial[i] = ((ll) i * factorial[i - 1]) % MOD;
    }

    // powers of k
    powers_of_k[0] = 1;
    for (int i = 1; i <= n; ++i) {
        powers_of_k[i] = ((ll) k * powers_of_k[i - 1]) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    preprocess(n, k);
    cout << calculate(n, k);
    return 0;
}

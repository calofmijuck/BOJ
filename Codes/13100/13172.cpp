#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

ll mod_pow(ll base, ll exp) {
    ll result = 1;
    while (exp) {
        if (exp & 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

ll mod_inv(ll n) {
    return mod_pow(n, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int m;
    cin >> m;

    ll expectation = 0;
    for (int i = 0; i < m; ++i) {
        ll n, s;
        cin >> n >> s;
        expectation = (expectation + s * mod_inv(n)) % MOD;
    }
    cout << expectation;
    return 0;
}

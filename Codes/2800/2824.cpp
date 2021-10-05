#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1000000000;

bool prime[40040];

void prime_sieve() {
    memset(prime, true, sizeof(prime));
    for (int p = 2; p <= 40000; ++p) {
        if (!prime[p]) {
            continue;
        }

        for (int i = p * p; i <= 40000; i += p) {
            prime[i] = false;
        }
    }
}

vector<pii> factorize(int x) {
    vector<pii> factors;
    for (int i = 2; i < 40000; ++i) {
        if (!prime[i]) {
            continue;
        }

        int exponent = 0;
        while (x % i == 0) {
            exponent++;
            x /= i;
        }

        if (exponent != 0) {
            factors.emplace_back(i, exponent);
        }

        if (x == 1) {
            break;
        }
    }

    if (x != 1) {
        factors.emplace_back(x, 1);
    }
    return factors;
}

map<int, int> prime_factorization() {
    int n;
    cin >> n;
    map<int, int> factorization;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        vector<pii> factors = factorize(x);
        for (pii factor : factors) {
            int divisor = factor.first, exponent = factor.second;
            factorization[divisor] += exponent;
        }
    }
    return factorization;
}

pair<ll, bool> find_gcd(map<int, int>& a, map<int, int>& b) {
    ll gcd = 1;
    bool overflow = false;

    for (auto it = a.begin(); it != a.end(); ++it) {
        ll divisor = it -> first;
        if (b[divisor] == 0) {
            continue;
        }

        int min_exponent = min(it -> second, b[divisor]);
        for (int i = 0; i < min_exponent; ++i) {
            if (gcd * divisor >= MOD) {
                overflow = true;
            }
            gcd = (gcd * divisor) % MOD;
        }
    }
    return make_pair(gcd, overflow);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    prime_sieve();

    map<int, int> a = prime_factorization();
    map<int, int> b = prime_factorization();

    auto [gcd, overflow] = find_gcd(a, b);
    if (!overflow) {
        cout << gcd;
    } else {
        cout << setfill('0') << setw(9) << gcd;
    }
    return 0;
}

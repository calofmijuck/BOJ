#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<typename T>
class extended_euclidean {
public:
    // ax + by = gcd(a, b)
    T a, x, b, y, gcd;

    extended_euclidean(T a, T b) {
        T old_r = a, r = b;
        T old_s = 1, s = 0;
        T old_t = 0, t = 1;

        while (r != 0) {
            T quotient = old_r / r;
            T tmp;

            tmp = r;
            r = old_r - quotient * r;
            old_r = tmp;

            tmp = s;
            s = old_s - quotient * s;
            old_s = tmp;

            tmp = t;
            t = old_t - quotient * t;
            old_t = tmp;
        }

        std::tie(a, x, b, y, gcd) = {a, old_s, b, old_t, old_r};
    }
};

ll chinese_remainder_theorem(vector<ll>& remainder, vector<ll>& modulus) {
    ll merged_r = remainder[0];
    ll merged_m = modulus[0];

    for (int i = 1; i < (int) modulus.size(); ++i) {
        extended_euclidean<ll> bezout(merged_m, modulus[i]);

        ll gcd = bezout.gcd;
        if ((merged_r - remainder[i]) % gcd != 0) {
            return -1;
        }

        ll lcm = merged_m / gcd * modulus[i];
        merged_r = ((__int128_t) remainder[i] - merged_r) % modulus[i] * bezout.x % modulus[i] / gcd * merged_m + merged_r;
        if (merged_r < 0) {
            merged_r += lcm;
        }

        merged_m = lcm;
    }

    return merged_r % merged_m;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    vector<ll> remainder, modulus;
    remainder.resize(3);
    modulus.resize(3);

    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 3; ++i) {
            cin >> modulus[i];
        }

        for (int i = 0; i < 3; ++i) {
            cin >> remainder[i];
        }

        cout << chinese_remainder_theorem(remainder, modulus) << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

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

typedef long long ll;

ll gcd_extended(ll a, ll b, ll* x, ll* y) {
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }

    ll x1, y1;
    ll g = gcd_extended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return g;
}

int main() {
    ll a = 6003722857, b = 77695236973;
    ll x, y;
    ll g = gcd_extended(a, b, &x, &y);
    printf("gcd(%lld, %lld) = %lld\n", a, b, g);
    printf("%lld * %lld + %lld * %lld = %lld\n", a, x, b, y, g);
}

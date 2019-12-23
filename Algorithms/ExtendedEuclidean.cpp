#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcdExt(ll a, ll b, ll* x, ll* y) {
    if(a == 0) {
        *x = 0, *y = 1;
        return b;
    }
    ll x1, y1;
    ll g = gcdExt(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return g;
}

int main() {
    ll a = 6003722857, b = 77695236973;
    ll x, y;
    ll g = gcdExt(a, b, &x, &y);
    printf("gcd(%lld, %lld) = %lld\n", a, b, g);
    printf("%lld * %lld + %lld * %lld = %lld\n", a, x, b, y, g);
}

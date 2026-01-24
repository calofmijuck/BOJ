#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(ll x, ll y) {
    ll g = gcd(x, y);
    x /= g;
    y /= g;

    printf("%lld %lld %lld %lld\n", 3 * x, y, 4 * x, 2 * y);
}

int main() {
    int t;
    scanf("%d", &t);

    ll x, y;
    while (t--) {
        scanf("%lld %lld", &x, &y);
        solve(x, y);
    }
    return 0;
}

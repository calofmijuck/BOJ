#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef __uint128_t uint128;

unordered_map<ull, ull> dp;

uint128 exponentiation(uint128 a, uint128 b, uint128 m) {
    if (b == 0) {
        return 2 % m;
    } else if (b == 1) {
        return a % m;
    }

    if (dp.find(b) != end(dp)) {
        return dp[b];
    }

    if (b % 2 == 0) {
        uint128 t = exponentiation(a, b / 2, m);
        dp[b] = (t * t - 2 + m) % m;
    } else {
        uint128 half = b / 2;
        dp[b] = (exponentiation(a, half + 1, m) * exponentiation(a, half, m) - a + m) % m;
    }

    return dp[b];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ull a, b, m;
    cin >> a >> b >> m;

    cout << (ull) exponentiation(a, b, m);
    return 0;
}
